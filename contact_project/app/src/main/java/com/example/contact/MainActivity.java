package com.example.contact;

import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;
import androidx.swiperefreshlayout.widget.SwipeRefreshLayout;

import android.Manifest;
import android.content.Intent;
import android.database.Cursor;
import android.net.Uri;
import android.os.Bundle;
import android.os.Handler;
import android.provider.ContactsContract;
import android.text.Editable;
import android.text.TextWatcher;
import android.view.View;
import android.widget.EditText;
import android.widget.ImageButton;
import android.widget.Toast;

import com.gun0912.tedpermission.PermissionListener;
import com.gun0912.tedpermission.normal.TedPermission;

import java.security.Permission;
import java.util.ArrayList;
import java.util.LinkedHashSet;
import java.util.List;

public class MainActivity extends AppCompatActivity {

    private ArrayList<Contact> datalist = new ArrayList<>();
    private ArrayList<Contact> filteredList = new ArrayList<>();
    private RecyclerView recyclerView;
    private Adapter adapter;
    private EditText search;
    private ImageButton add;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        recyclerView = findViewById(R.id.main_recy); // main_recy랑 recyclerView 연결
        search = findViewById(R.id.search_tv);
        add = findViewById(R.id.add);

        SwipeRefreshLayout mSwipeRefreshLayout = findViewById(R.id.refresh_layout);
        mSwipeRefreshLayout.setOnRefreshListener(new SwipeRefreshLayout.OnRefreshListener() {
            @Override
            public void onRefresh() {
                datalist = new ArrayList<>();
                datalist.clear();
                datalist = getContactList();
                adapter.notifyDataSetChanged();
                recyclerView.setAdapter(adapter);

                final Handler handler = new Handler();
                handler.postDelayed(new Runnable() {
                    @Override
                    public void run() {
                        mSwipeRefreshLayout.setRefreshing(false);
                    }
                }, 500);
            }
        });

        // 전화랑 연락처에 액세스하는 권한 필요
        PermissionListener permissionListener = new PermissionListener() {
            @Override
            // 권한이 허락이 된다면
            public void onPermissionGranted() {
                datalist.clear();
                datalist = getContactList();
                adapter = new Adapter(MainActivity.this, datalist);
                recyclerView.setLayoutManager(new LinearLayoutManager(getApplicationContext())); // recyclerView를 linear하게 보여주겠다고 설정
                recyclerView.setAdapter(adapter);

                search.addTextChangedListener(new TextWatcher() {
                    @Override
                    public void beforeTextChanged(CharSequence s, int start, int count, int after) {
                        // 글자 쓰기 전에 할 일 없음
                    }

                    @Override
                    public void onTextChanged(CharSequence s, int start, int before, int count) {
                    }

                    @Override
                    public void afterTextChanged(Editable s) {
                        String searchText = search.getText().toString(); // 검색어 받아오고
                        searchFilter(searchText);
                    }
                }); // addText 창에 글자가 써지는 걸 감지
            }

            @Override
            // 권한이 거부된다면
            public void onPermissionDenied(List<String> deniedPermissions) {
                Toast.makeText(MainActivity.this, "권한 거부", Toast.LENGTH_SHORT).show();
            }
        };
        // 권한 설정
        TedPermission.create()
                .setPermissionListener(permissionListener)
                .setRationaleMessage("주소록의 띄우고 전화를 걸기 위해서는 권한이 필요합니다")
                .setDeniedMessage("[설정] > [권한] 에서 권한을 허용할 수 있습니다")
                .setPermissions(new String[]{Manifest.permission.CALL_PHONE, Manifest.permission.READ_CONTACTS, Manifest.permission.WRITE_CONTACTS})
                .check();

        add.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(Intent.ACTION_INSERT, ContactsContract.Contacts.CONTENT_URI);
                startActivity(intent);
            }
        });
    }

    @Override
    protected void onRestart() {
        super.onRestart(); // datalist에 변화가 있을 때 datalist를 새로 로딩하여 recyclerview에 바뀐 datalist를 반영하기 위해서 override
        datalist = new ArrayList<>();
        datalist.clear();
        // datalist = getContactList();
        adapter = new Adapter(MainActivity.this, datalist);
        recyclerView.setAdapter(adapter);  // recyclerView에 새로운 adapter setting

    }

    // 검색 기능 구현
    public void searchFilter(String searchText){
        filteredList.clear();
        for (int i = 0; i < datalist.size(); i++) {
            if (datalist.get(i).getName().toLowerCase().contains(searchText.toLowerCase()) ||
                    datalist.get(i).getPhoneNumber().contains(searchText)) { // 검색어(다 소문자)가 datalist(다 소문자)에 있으면 if문 진입
                filteredList.add(datalist.get(i));
            }
        }
        adapter.filterList(filteredList);
        recyclerView.setAdapter(adapter);
    }

    public ArrayList<Contact> getContactList() {

        //
        LinkedHashSet<Contact> hasList = new LinkedHashSet<>(); // 저장된 순서를 유지시키며 객체를 중복없이 저장하는 set
        ArrayList<Contact> contactsList; // 얘가 바로 반환할 List!

        hasList.clear();

        Uri uri = ContactsContract.CommonDataKinds.Phone.CONTENT_URI; // 핸드폰에 있는 데이터의 위치를 받아옴

        // 어떤 걸 받아올지
        String[] projection = new String[]{ContactsContract.CommonDataKinds.Phone.NUMBER,
                ContactsContract.CommonDataKinds.Phone.DISPLAY_NAME}; // Table에서 { column 0(number) , column 1(name) }

        // 어떤 식으로 정렬할 지
        String sortOrder = ContactsContract.Contacts.DISPLAY_NAME + " COLLATE LOCALIZED ASC";

        Cursor cursor = getContentResolver().query(uri, projection, null, null, sortOrder);

        if (cursor.moveToFirst()) {
            do {
                Contact myContact = new Contact();
                myContact.setPhoneNumber(cursor.getString(0));
                myContact.setName(cursor.getString(1));

                if (myContact.getPhoneNumber().startsWith("01")) {
                    hasList.add(myContact);
                }
            } while (cursor.moveToNext());
        }

        contactsList = new ArrayList<>(hasList);

        if (cursor != null){
            cursor.close();
        }
        return contactsList;
    }




}