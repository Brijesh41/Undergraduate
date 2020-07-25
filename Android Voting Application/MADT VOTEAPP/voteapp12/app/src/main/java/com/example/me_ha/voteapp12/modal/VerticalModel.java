package com.example.me_ha.voteapp12.modal;

import java.util.ArrayList;

public class VerticalModel {
    String title;
    int Partydp;
    ArrayList<HorizontalModel> arrayList;

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public ArrayList<HorizontalModel> getArrayList() {
        return arrayList;
    }

    public int getPartydp() {
        return Partydp;
    }

    public void setPartydp(int partydp) {
        Partydp = partydp;
    }

    public void setArrayList(ArrayList<HorizontalModel> arrayList) {
        this.arrayList = arrayList;
    }

}
