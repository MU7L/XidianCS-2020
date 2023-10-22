package org.example;

import java.io.Serializable;

public class Book implements Serializable {
    public int bookID;
    public String name;
    public Book(int bookID, String name) {
        this.bookID = bookID;
        this.name = name;
    }

    @Override
    public String toString() {
        return "Book {" +
                "bookID = " + bookID +
                ", name = '" + name + '\'' +
                '}';
    }
}
