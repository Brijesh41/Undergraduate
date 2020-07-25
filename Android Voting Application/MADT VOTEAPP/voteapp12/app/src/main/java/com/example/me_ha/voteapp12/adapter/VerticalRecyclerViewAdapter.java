package com.example.me_ha.voteapp12.adapter;

import android.content.Context;
import android.support.annotation.NonNull;
import android.support.v7.widget.LinearLayoutManager;
import android.support.v7.widget.RecyclerView;
import android.view.LayoutInflater;
import android.view.ViewGroup;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;

import com.example.me_ha.voteapp12.R;
import com.example.me_ha.voteapp12.modal.HorizontalModel;
import com.example.me_ha.voteapp12.modal.VerticalModel;

import java.util.ArrayList;

public class VerticalRecyclerViewAdapter extends RecyclerView.Adapter<VerticalRecyclerViewAdapter.VerticalRVViewHolder> {

    Context context;
    ArrayList<VerticalModel> arrayList;
    public VerticalRecyclerViewAdapter(Context context,ArrayList<VerticalModel> arrayList)
    {
        this.context=context;
        this.arrayList=arrayList;
    }
    public VerticalRVViewHolder onCreateViewHolder(ViewGroup parent, int viewType) {
        View view= LayoutInflater.from(parent.getContext()).inflate(R.layout.item_vertical,parent,false);
        return new VerticalRVViewHolder(view);
    }


    public class VerticalRVViewHolder extends RecyclerView.ViewHolder{
        RecyclerView recyclerView;
        TextView textView;
        Button button;
        ImageView partyImage;

        public VerticalRVViewHolder(View itemView) {
            super(itemView);
            recyclerView = (RecyclerView)itemView.findViewById(R.id.recyclerview1);
            textView=(TextView)itemView.findViewById(R.id.title1);
            partyImage = (ImageView)itemView.findViewById(R.id.partyimg);

        }
    }


    @Override
    public void onBindViewHolder(VerticalRVViewHolder holder, int position) {
        final VerticalModel verticalModel=arrayList.get(position);
        String title=verticalModel.getTitle();
        ArrayList<HorizontalModel> singleItem=verticalModel.getArrayList();
        int dp = verticalModel.getPartydp();
        holder.textView.setText(title);
        holder.partyImage.setImageResource(dp);
        HorizontalRecyclerViewAdapter horizontalRecyclerViewAdapter=new HorizontalRecyclerViewAdapter(context,singleItem);

        holder.recyclerView.setHasFixedSize(true);
        holder.recyclerView.setLayoutManager(new LinearLayoutManager(context,LinearLayoutManager.HORIZONTAL,false));

        holder.recyclerView.setAdapter(horizontalRecyclerViewAdapter);

    }

    @Override
    public int getItemCount() {
        return arrayList.size();
    }
}
