package com.example.me_ha.voteapp12;

import android.content.Context;
import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.Gravity;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.ListView;
import android.widget.TextView;
import android.widget.Toast;

public class act2 extends AppCompatActivity {


    Button b1;
    TextView t1;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_act2);
        t1 = (TextView) findViewById(R.id.textViewka);
        b1 = (Button) findViewById(R.id.buttonka);
        b1.setOnClickListener(new View.OnClickListener() {


            @Override
            public void onClick(View v) {

                LayoutInflater li = getLayoutInflater();
                 v= li.inflate(R.layout.custom_toast,(ViewGroup) findViewById(R.id.ll));
                Toast t =  new Toast(getApplicationContext());
                t.setDuration(Toast.LENGTH_SHORT);
                t.setGravity(Gravity.CENTER_VERTICAL,0,0);
                t.setView(v);
                t.show();

            }
        });
        String a[] = {"a"};
        ArrayAdapter adapter = new ArrayAdapter(this,R.layout.activity_act2,a);
        ListView l = (ListView) findViewById(R.id.f);
        l.setAdapter(adapter);

      }


}
