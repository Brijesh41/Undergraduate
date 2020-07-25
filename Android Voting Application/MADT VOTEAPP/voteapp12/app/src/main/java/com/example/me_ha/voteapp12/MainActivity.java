package com.example.me_ha.voteapp12;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.support.v7.widget.LinearLayoutManager;
import android.support.v7.widget.RecyclerView;
import android.widget.ArrayAdapter;
import android.widget.ListAdapter;
import android.widget.ListView;

import com.example.me_ha.voteapp12.adapter.HorizontalRecyclerViewAdapter;
import com.example.me_ha.voteapp12.adapter.VerticalRecyclerViewAdapter;
import com.example.me_ha.voteapp12.modal.HorizontalModel;
import com.example.me_ha.voteapp12.modal.VerticalModel;

import java.util.AbstractSequentialList;
import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }


    }

