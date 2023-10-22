// TODO: 哈希算法

import java.math.BigInteger;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class MyHash {
    public static final int MAX_HASH = 99999;

    static int hash(String str) {
        String _str = String.format("%7s", str);
        _str = _str.replace(" ", "0");
        // if (str.length() == 4) str = str + "000";
        // if (str.length() == 3) str = str + "0000";
        int res = (int) calculateHash(_str);
        System.out.println(String.format("[hash(%s) = %d]", _str, res));
        return res;
    }

    private static long calculateHash(String input) {
        try {
            // 创建MD5哈希函数实例
            MessageDigest md = MessageDigest.getInstance("MD5");

            // 计算哈希值
            byte[] hashBytes = md.digest(input.getBytes());

            // 提取子串（第11位到第17位）
            String hexHash = new BigInteger(1, hashBytes).toString(16);
            String substring = hexHash.substring(10, 17);

            // 将子串转换为整数
            int intValue = Integer.parseInt(substring, 16);

            // 使用hashCode()方法计算整数的哈希值
            int hashCode = Integer.hashCode(intValue);

            // 截取倒数第1位到第5位的子串
            String hashSubstring = String
                    .valueOf(hashCode)
                    .substring(
                            Math.max(String.valueOf(hashCode).length() - 5, 0
                            ));

            // 将子串转换为整数
            return Long.parseLong(hashSubstring);
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
        }
        return 0;
    }


}
