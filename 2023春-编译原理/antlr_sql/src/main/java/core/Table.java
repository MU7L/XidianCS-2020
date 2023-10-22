package core;

import java.util.*;

// 表的列实现 在Database中调用
public class Table {
    String name; // 表名
    List<Meta> header; // 表头
    Map<String, List<Meta>> body; // 数据
    private int metaWidth;

    public Table(String name, List<String> fields, List<Meta.Type> types) {
        this.name = name;
        this.metaWidth = 0;
        this.header = new ArrayList<>();
        for (int i = 0; i < fields.size(); i++) {
            String field = fields.get(i);
            this.header.add(new Meta(field, types.get(i)));
            this.metaWidth = Math.max(this.metaWidth, field.length());
        }
        this.body = new HashMap<>();
        for (Meta meta : header) {
            this.body.put(meta.key, new ArrayList<>());
        }
    }

    // 查找
    public Table select(List<String> fields) {
        List<Meta.Type> types = new ArrayList<>();
        Map<String, List<Meta>> newBody = new HashMap<>();
        for (Meta field : this.header) {
            if (fields.contains(field.key)) {
                types.add(field.type);
                newBody.put(field.key, this.body.get(field.key));
            }
        }
        Table t = new Table("selected", fields, types);
        t.metaWidth = this.metaWidth;
        t.body = newBody;
        return t;
    }

    // 完整插入
    public void insert(List<Meta> values) {
        for (int i = 0; i < this.header.size(); i++) {
            Meta field = this.header.get(i);
            Meta value = values.get(i);
            this.metaWidth = Math.max(this.metaWidth, value.value.length());
            this.body.get(field.key).add(value);
        }
    }

    // 更新
    public int update(Map<String, String> updates) {
        int records = 0;
        for (Map.Entry<String, String> update : updates.entrySet()) {
            List<Meta> col = this.body.get(update.getKey());
            records = 0;
            for (Meta data : col) {
                String value = update.getValue();
                data.value = value;
                this.metaWidth = Math.max(this.metaWidth, value.length());
                records++;
            }
        }
        return records;
    }

    // 删除
    public int delete() {
        int records = 0;
        for (Meta meta : header) {
            List<Meta> col = this.body.get(meta.key);
            records = col.size();
            col.clear();
        }
        return records;
    }

    public String toCSV() {
        StringBuilder sb = new StringBuilder();
        // 表头
        for (Meta field : header) {
            sb.append(field.key).append(",");
        }
        sb.deleteCharAt(sb.length() - 1);
        sb.append('\n');
        // 类型
        for (Meta field : header) {
            sb.append(field.type).append(",");
        }
        sb.deleteCharAt(sb.length() - 1);
        sb.append('\n');
        // 数据
        for (int line = 0; line < body.get(header.get(0).key).size(); line++) {
            for (Meta field : header) {
                Meta data = body.get(field.key).get(line);
                sb.append(data).append(",");
            }
            sb.deleteCharAt(sb.length() - 1);
            sb.append('\n');
        }
        sb.deleteCharAt(sb.length() - 1);
        return sb.toString();
    }

    private String getSplitLine() {
        StringBuilder sb = new StringBuilder();
        for(Meta h: header) {
            sb.append('+');
            for (int i = 0; i < metaWidth; i++) {
                sb.append('-');
            }
        }
        sb.append('+');
        return sb.toString();
    }

    @Override
    // 输出到控制台
    public String toString() {
        StringBuilder sb = new StringBuilder();
        String csv = toCSV();
        String splitLine = getSplitLine();
        String[] lines = csv.split("\n");
        // 顶盖
        sb.append(splitLine).append('\n');
        // 表头
        String[] headers = lines[0].split(",");
        for(String h: headers) {
            sb
                    .append('|')
                    .append(" ".repeat(Math.max(0, metaWidth - h.length())))
                    .append(h);
        }
        sb.append("|\n");
        // 分界
        sb.append(splitLine).append('\n');
        // 数据
        for(int i = 2; i < lines.length; i++){
            String[] metas = lines[i].split(",");
            for(String m: metas) {
                sb
                        .append('|')
                        .append(" ".repeat(Math.max(0, metaWidth - m.length())))
                        .append(m);
            }
            sb.append("|\n");
        }
        // 封底
        sb.append(splitLine);
        return sb.toString();
    }
}
