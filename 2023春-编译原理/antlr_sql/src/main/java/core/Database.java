package core;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

// 数据库 单例模式
public class Database {
    Map<String, Table> tables;
    static Database instance;

    private Database() {
        tables = new HashMap<>();
    }

    public static Database getInstance() {
        if (instance == null) {
            instance = new Database();
        }
        return instance;
    }

    private boolean notExist(String tableName) {
        return !tables.containsKey(tableName);
    }

    public String create(String tableName, List<String> fields, List<Meta.Type> types) {
        if (tables.containsKey(tableName)) return String.format("表 %s 已存在", tableName);
        Table t = new Table(tableName, fields, types);
        tables.put(tableName, t);
        return "创建 1 个表：" + tableName;
    }

    public String show() {
        StringBuilder sb = new StringBuilder();
        for (String tableName : tables.keySet()) sb.append(tableName).append('\n');
        sb.append("共 ").append(tables.size()).append(" 个表");
        return sb.toString();
    }

    public String drop(String tableName) {
        if (notExist(tableName)) return "没有此表";
        tables.remove(tableName);
        return "移除 1 个表";
    }

    // 完整插入
    public String insert(String tableName, List<String> values) {
        if (notExist(tableName)) return "没有此表";
        Table t = tables.get(tableName);
        List<Meta> _values = new ArrayList<>();
        // 类型检查
        for (int i = 0; i < t.header.size(); i++) {
            String value = values.get(i);
            Meta _field = t.header.get(i);
            if (Meta.checkType(value, _field.type)) {
                _values.add(new Meta(_field.key, _field.type, value));
            } else return String.format("值 %s 不匹配域 %s 的类型 %s", value, _field.key, _field.type);
        }
        t.insert(_values);
        return "插入 1 条记录";
    }

    // 部分插入
    public String insert(String tableName, List<String> values, List<String> fields) {
        if (notExist(tableName)) return "没有此表";
        Table t = tables.get(tableName);
        List<Meta> _values = new ArrayList<>(); // 最终使用的values
        // 整理输入为 map
        Map<String, String> _insert = new HashMap<>();
        for (int i = 0; i < values.size(); i++) {
            _insert.put(fields.get(i), values.get(i));
        }
        // 类型检查 生成Meta数组
        for (int i = 0; i < t.header.size(); i++) {
            Meta _field = t.header.get(i);  // 表头
            if (_insert.containsKey(_field.key)) {
                // 插入参数 类型检查
                String value = _insert.get(_field.key); // 待插入值
                if (!Meta.checkType(value, _field.type)) {
                    return String.format("值 %s 不匹配域 %s 的类型 %s", value, _field.key, _field.type);
                }
                _values.add(new Meta(_field.key, _field.type, value));
            } else {
                // 插入默认值
                _values.add(new Meta(_field.key, _field.type, Meta.DEFAULT_VALUE));
            }
        }

        tables.get(tableName).insert(_values);
        return "插入 1 条记录";
    }

    public String select(String tableName, List<String> fields) {
        if (notExist(tableName)) return "没有此表";
        Table t = tables.get(tableName).select(fields);
        return t.toString();
    }

    public String select(String tableName) {
        if (notExist(tableName)) return "没有此表";
        Table t = tables.get(tableName);
        return t.toString();
    }

    public String update(String tableName, List<String> values, List<String> fields) {
        if (notExist(tableName)) return "没有此表";
        Table t = tables.get(tableName);
        Map<String, String> _values = new HashMap<>();
        for (int i = 0; i < values.size(); i++) {
            String field = fields.get(i);
            Meta _field = null;
            for (Meta _f : t.header) {
                if (_f.key.equals(field)) {
                    _field = _f;
                    break;
                }
            }
            if (_field == null) return "不存在域 " + field;
            String value = values.get(i);
            if (!Meta.checkType(value, _field.type)) {
                return String.format("值 %s 不匹配域 %s 的类型 %s", value, _field.key, _field.type);
            }
            _values.put(field, value);
        }

        int records = t.update(_values);
        return String.format("更新 %d 条记录", records);
    }

    public String delete(String tableName) {
        if (notExist(tableName)) return "没有此表";
        int records = tables.get(tableName).delete();
        return String.format("删除 %d 条记录", records);
    }

}
