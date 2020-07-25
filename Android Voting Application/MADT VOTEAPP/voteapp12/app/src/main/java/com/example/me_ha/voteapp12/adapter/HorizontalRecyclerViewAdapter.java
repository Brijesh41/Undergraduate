package com.example.me_ha.voteapp12.adapter;

import android.content.Context;
import android.content.Intent;
import android.support.v7.widget.RecyclerView;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;

import com.example.me_ha.voteapp12.R;
import com.example.me_ha.voteapp12.modal.HorizontalModel;

import java.util.ArrayList;

public class HorizontalRecyclerViewAdapter extends RecyclerView.Adapter<HorizontalRecyclerViewAdapter.HorizontalRVViewHolder> {
    Context context;
    ArrayList<HorizontalModel> arrayList;

    public HorizontalRecyclerViewAdapter(Context context,ArrayList<HorizontalModel> arrayList)
    {
        this.context=context;
        this.arrayList=arrayList;
    }


    public HorizontalRVViewHolder onCreateViewHolder(ViewGroup parent, int viewType) {
        View view = LayoutInflater.from(parent.getContext()).inflate(R.layout.item_horizontal,parent,false);
        return new HorizontalRVViewHolder(view);
    }


    public void onBindViewHolder(HorizontalRVViewHolder holder, int position) {
        final HorizontalModel horizontalModel=arrayList.get(position);
        holder.persontitle.setText(horizontalModel.getName());
        holder.personimage.setImageResource(horizontalModel.getDp());
        holder.itemView.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Toast.makeText(context,horizontalModel.getName(), Toast.LENGTH_SHORT).show();
              Intent intent = new Intent(context,horizontalModel.getDest());
              context.startActivity(intent);
            }
        });
    }


    public int getItemCount() {
        return arrayList.size();
    }

    public class HorizontalRVViewHolder extends RecyclerView.ViewHolder {

        TextView persontitle;
        ImageView personimage;
        public HorizontalRVViewHolder(View itemView) {
            super(itemView);
            personimage = (ImageView) itemView.findViewById(R.id.personimage);
            persontitle = (TextView) itemView.findViewById(R.id.persontitle);

        }
    }

}
