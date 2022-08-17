package com.example.contact;

import android.app.AlertDialog;
import android.content.ContentProviderOperation;
import android.content.ContentResolver;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.OperationApplicationException;
import android.database.Cursor;
import android.net.Uri;
import android.os.RemoteException;
import android.provider.ContactsContract;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.constraintlayout.widget.ConstraintLayout;
import androidx.recyclerview.widget.RecyclerView;

import java.lang.reflect.Array;
import java.util.ArrayList;

public class Adapter extends RecyclerView.Adapter<Adapter.Holder> {

    private Context context;
    private ArrayList<Contact> datalist;

    public Adapter(Context context, ArrayList<Contact> datalist){
        this.context = context;
        this.datalist = datalist;
    }


    @NonNull
    @Override
    public Holder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View view = LayoutInflater.from(context).inflate(R.layout.recy_item, parent,false);
        Holder holder = new Holder(view);
        return holder;
    }

    @Override
    public void onBindViewHolder(@NonNull Holder holder, int position) {
        Contact contact = datalist.get(position);  // position -> 데이터의 몇번째 데이터인지 나타내는 인덱스
        holder.name.setText(contact.getName());    // contact 객체 안에 있는 이름을 불러와서 넣겠다!
        holder.phoneNum.setText(contact.getPhoneNumber());

        holder.call.setOnClickListener(new View.OnClickListener() { // setOnClickListener: 버튼이 클릭되었는지 아닌지 감지하는 것
            @Override
            public void onClick(View v) {

                AlertDialog.Builder builder = new AlertDialog.Builder(context);
                builder.setTitle("전화를 걸지, 문자를 보낼지 선택해 주세요.");
                builder.setMessage("골라~~~");
                builder.setNeutralButton("전화걸기", new DialogInterface.OnClickListener() { // DialogInterface.OnclickListener: Dialog의 버튼이 클릭되었는지, 아닌지 감지
                    @Override
                    public void onClick(DialogInterface dialog, int which) {
                        String number = datalist.get(position).getPhoneNumber(); // intent를 통해 번호를 넘겨주기 위해 datalist에 접근해서 번호를 number에 저장
                        Uri numberU = Uri.parse("tel:" + number); // 위에서 선언한 number는 핸드폰이 못알아먹음! -> 알아들을 수 있게 형변환 한번 해주기
                        // uri -> 인터넷 주소(url)가 uri의 일종. 한마디로 주소같은 것.
                        Intent call = new Intent(Intent.ACTION_CALL, numberU); // Intent.ACTION_CALL : 어느 화면으로 바뀔 지 선언(전화거는 화면으로 전환할거야)
                        context.startActivity(call.addFlags(Intent.FLAG_ACTIVITY_NEW_TASK)); // startAcivity -> 만든 intent를 보내는 함수
                    }
                });
                builder.setPositiveButton("문자 보내기", new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which) {
                        Uri smsUri = Uri.parse("tel:" + contact.getPhoneNumber());
                        Intent intent = new Intent(Intent.ACTION_VIEW, smsUri);
                        intent.putExtra("address:", contact.getPhoneNumber());  // putExtra: 인텐트에 내가 더 보내고 싶은 정보를 추가
                        intent.putExtra("sms_body", "");
                        intent.setType("vnd.android-dir/mms-sms");  // setType: intent의 종류를 선언
                        context.startActivity(intent.addFlags(Intent.FLAG_ACTIVITY_NEW_TASK));
                    }
                });
                builder.create().show();
            }
        });

        holder.item_container.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                AlertDialog.Builder builder = new AlertDialog.Builder(context);
                builder.setTitle("삭제");
                builder.setMessage("이 연락처를 삭제하시겠습니까?");
                builder.setNegativeButton("아니오.", null);
                builder.setPositiveButton("예.", new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which) {
                        //TODO : 핸드폰에서 연락처 지우기.
                        datalist.remove(position);
                        notifyItemRemoved(position);
                        notifyItemRangeChanged(position, datalist.size());
                    }
                });
                builder.create().show();
            }
        });

        holder.item_container.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                AlertDialog.Builder builder = new AlertDialog.Builder(context);
                builder.setTitle("삭제");
                builder.setMessage(("정말 삭제할꼬야?"));
                builder.setNegativeButton("아니오", null);
                builder.setPositiveButton("예", new DialogInterface.OnClickListener() {
                    @Override
                    // 삭제에 예라고 했으니 1. recyclerView에서도 삭제 2. 핸드폰에서도 삭제
                    public void onClick(DialogInterface dialog, int which) {
                        deleteContactFromNumer(context.getContentResolver(), datalist.get(position).getPhoneNumber());
                        datalist.remove(position);
                        // datalist에서 지웠으니 datalist가 바꼈다고 adapter한테 알려줘야 함 -> notify 사용
                        notifyItemRemoved(position);
                        notifyItemRangeChanged(position, datalist.size());
                    }
                });
                builder.create().show();
            }
        });

    }

    @Override
    public int getItemCount() {
        return datalist.size();
    }

    public class Holder extends RecyclerView.ViewHolder {

        protected ConstraintLayout item_container;
        protected TextView name;
        protected TextView phoneNum;
        protected Button call;

        public Holder(@NonNull View itemView) {
            super(itemView);

            item_container = itemView.findViewById(R.id.item_container);
            name = itemView.findViewById(R.id.name);
            phoneNum = itemView.findViewById(R.id.phoneNum);
            call = itemView.findViewById(R.id.call);
        }
    }

    public void filterList(ArrayList<Contact> filteredList){
        datalist = filteredList;
        notifyDataSetChanged(); // dataSet이 바뀐걸 알려주는 함수
    }

    private static long getContactIDFromNumber(ContentResolver contactHelper, String number){

        // parameter로 받은 number가 있는 행의 위치를 테이블에서 찾겠다
        Uri contactUri = Uri.withAppendedPath(ContactsContract.PhoneLookup.CONTENT_FILTER_URI, Uri.encode(number));

        String[] projection = {ContactsContract.PhoneLookup._ID};

        Cursor cursor = contactHelper.query(contactUri, projection, null, null, null);

        if (cursor.moveToFirst()){
            return cursor.getLong(cursor.getColumnIndex(ContactsContract.PhoneLookup._ID));
        }
        else if (cursor != null){
            cursor.close();
        }
        return -1;
    }

    public static void deleteContactFromNumer(ContentResolver contactHelper, String number){

        ArrayList<ContentProviderOperation> ops = new ArrayList<>();
        String[] WhereArgs = new String[] {String.valueOf(getContactIDFromNumber(contactHelper, number))};

        ops.add(ContentProviderOperation.newDelete(ContactsContract.RawContacts.CONTENT_URI)
                .withSelection(ContactsContract.RawContacts.CONTACT_ID + "=?", WhereArgs).build());

        try {
            contactHelper.applyBatch(ContactsContract.AUTHORITY, ops);
        } catch (OperationApplicationException e) {
            e.printStackTrace();
        } catch (RemoteException e) {
            e.printStackTrace();
        }
    }
}
