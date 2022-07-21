package com.example.contact;

import android.app.AlertDialog;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.net.Uri;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.constraintlayout.widget.ConstraintLayout;
import androidx.recyclerview.widget.RecyclerView;

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
        Contact contact =datalist.get(position);
        holder.name.setText(contact.getName());
        holder.phoneNum.setText(contact.getPhoneNumber());

        holder.call.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                AlertDialog.Builder builder = new AlertDialog.Builder(context);
                builder.setTitle("전화를 걸지, 문자를 보낼지 선택해 주세요.");
                builder.setMessage("골라~~~");
                builder.setNeutralButton("전화걸기", new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which) {
                        String number = datalist.get(position).getPhoneNumber();
                        Uri numberU = Uri.parse("tel:" + number);
                        Intent call = new Intent(Intent.ACTION_CALL, numberU);
                        context.startActivity(call.addFlags(Intent.FLAG_ACTIVITY_NEW_TASK));

                    }
                });

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
}
