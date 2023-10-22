package MapRouting.alg;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

// 读取txt
public class ReadTxt {
    private BufferedReader bufferedReader = null;

    public ReadTxt(String txtPath) throws FileNotFoundException {
        bufferedReader = new BufferedReader(new FileReader(txtPath));
    }

    // 读取下一行
    public String nextLine() {
        // return bufferedReader.readLine();
        String line = null;
        try {
            line = bufferedReader.readLine();
            line = line.trim().replaceAll("\\s+", " ");
        } catch (IOException e) {
            e.printStackTrace();
            line = null;
        } finally {
            return line;
        }
    }

    // 关闭读取
    public void close() throws IOException {
        bufferedReader.close();
    }

    // 测试
    public static void main(String[] args) {
        ReadTxt txt = null;
        try {
            // txt = new ReadTxt("D:\\single\\Algorithms\\test.txt");
            txt = new ReadTxt("D:\\single\\Algorithms\\usamap.txt");
            String line = null;
            while((line = txt.nextLine()) != null) {
                System.out.println(line);
                // System.out.println(line);
            }
            txt.close();
        } catch (IOException e) {
            System.out.println("?");
            e.printStackTrace();
        }

    }
}
