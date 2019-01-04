import java.util.Scanner;
import java.util.ArrayList;

public class Solution {
    private ArrayList<String> hands = new ArrayList<>();
    private ArrayList<String> eyes = new ArrayList<>();
    private ArrayList<String> mouses = new ArrayList<>();

    public void run() {
        String s = "";
        Scanner in = new Scanner(System.in);
        s = in.nextLine();
        System.out.println(s);
        var i = Integer.parseInt(s);
    }

    public static void main(String[] args) {
        Solution sln = new Solution();
        sln.run();
    }
}