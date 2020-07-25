package com.example.me_ha.voteapp12;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.support.v7.widget.LinearLayoutManager;
import android.support.v7.widget.RecyclerView;
import android.widget.ArrayAdapter;
import android.widget.ListView;

import com.example.me_ha.voteapp12.adapter.VerticalRecyclerViewAdapter;
import com.example.me_ha.voteapp12.modal.HorizontalModel;
import com.example.me_ha.voteapp12.modal.VerticalModel;

import java.util.ArrayList;

public class newmain extends AppCompatActivity {
    ListView l;
    ArrayList<VerticalModel> arrayListVertical;
    RecyclerView verticalRecyclerview;
    VerticalRecyclerViewAdapter adapter;

    String PARTY[]={"BJP","AAP","CONGRESS","RJD"};

    Class<?> destinations[] = {modi.class,Rahul.class,LaluP.class,Kejriwal.class,modi.class,Rahul.class,LaluP.class,Kejriwal.class,modi.class,Rahul.class,LaluP.class,Kejriwal.class,modi.class,Rahul.class,Kejriwal.class,LaluP.class};
    String partytitlelist[] = {"BJP","INC","AAP","RJD"};
    int partyimagelist[] = {R.drawable.bjp,R.drawable.inc,R.drawable.aap,R.drawable.rjd};
    String persontitlelist[] = {"Narendra Modi","Rahul Gandhi","Arvind Kejriwal","Lalu Prasad Yadav","Narendra Modi","Rahul Gandhi","Arvind Kejriwal","Lalu Prasad Yadav","Narendra Modi","Rahul Gandhi","Arvind Kejriwal","Lalu Prasad Yadav","Narendra Modi","Rahul Gandhi","Arvind Kejriwal","Lalu Prasad Yadav"};

    int personimagelist[] = {R.drawable.nr,R.drawable.sx,R.drawable.ar,R.drawable.lpr,R.drawable.nr,R.drawable.sx,R.drawable.ar,R.drawable.lpr,R.drawable.nr,R.drawable.sx,R.drawable.ar,R.drawable.lpr,R.drawable.nr,R.drawable.sx,R.drawable.ar,R.drawable.lpr};

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_newmain);
        arrayListVertical=new ArrayList<>();
        verticalRecyclerview = (RecyclerView) findViewById(R.id.recyclerview);
        verticalRecyclerview.setLayoutManager(new LinearLayoutManager(this, LinearLayoutManager.VERTICAL, false));
        adapter = new VerticalRecyclerViewAdapter(this, arrayListVertical);
        verticalRecyclerview.setAdapter(adapter);
        setData();
    }

    private void setData() {

        
        for(int i=1;i<5;i++)
        {
            VerticalModel verticalModel=new VerticalModel();
            verticalModel.setTitle(partytitlelist[i-1]);
            verticalModel.setPartydp(partyimagelist[i-1]);
            ArrayList<HorizontalModel> arrayListHorizontal = new ArrayList<>();

            for(int j=0;j<4;j++) {
                HorizontalModel horizontalModel = new HorizontalModel();
                horizontalModel.setName( persontitlelist[j]);
                horizontalModel.setDp(personimagelist[j]);
                horizontalModel.setDest(destinations[j]);

                arrayListHorizontal.add(horizontalModel);
            }

            verticalModel.setArrayList(arrayListHorizontal);
            arrayListVertical.add(verticalModel);
        }

        adapter.notifyDataSetChanged();
    }

}
