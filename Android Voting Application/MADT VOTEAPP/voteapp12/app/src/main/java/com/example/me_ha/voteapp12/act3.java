package com.example.me_ha.voteapp12;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

public class act3 extends AppCompatActivity {

    EditText e1;
    Button b1;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_act3);

        b1 = (Button) findViewById(R.id.buttonba);
        e1= (EditText) findViewById(R.id.editTextba);
                b1.setOnClickListener(new View.OnClickListener() {
                    @Override
                    public void onClick(View v) {

                        Intent i = new Intent();
                        String msg= e1.getText().toString();
                        i.putExtra("msg",msg);

                        setResult(2,i);
                        finish();
                    }
                });
    }
}
