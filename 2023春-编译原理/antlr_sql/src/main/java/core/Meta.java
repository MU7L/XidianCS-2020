package core;

import java.util.regex.Pattern;

// 元数据
public class Meta implements Comparable<Meta> {
    public enum Type {
        NUMBER, STRING;
    }

    public static final String DEFAULT_VALUE = "null";

    String key;
    Type type;
    String value;

    public Meta(String key, Type type, String value) {
        this.key = key;
        this.type = type;
        this.value = value;
    }

    public Meta(String key, Type type) {
        this.key = key;
        this.type = type;
        this.value = "";
    }

    // 类型检查
    static boolean checkType(String value, Type type) {
        if(value.equals(DEFAULT_VALUE)) return true;
        if(type == Type.STRING) {
            return Pattern.matches("^\".*\"$", value);
        } else {
            return Pattern.matches("\\d+", value);
        }
    }

    @Override
    public int compareTo(Meta o) {
        if (this.key.equals(o.key) && this.type == o.type) {
            if (this.type == Type.NUMBER) {
                return Integer.parseInt(this.value) - Integer.parseInt(o.value);
            } else {
                return this.value.compareTo(o.value);
            }
        } else {
            return -1;
        }
    }

    @Override
    public String toString() {
        return value;
    }
}
