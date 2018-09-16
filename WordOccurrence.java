import java.util.Collections;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.StringTokenizer;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Raihan
 */
public class WordOccurrence {
       public static void main(String[] args) {
       
        Integer i = 0;
        String line = null;
        Scanner scan = new Scanner(System.in);
        line = scan.nextLine();
        StringTokenizer st = new StringTokenizer(line, " ");
        Map<String, Integer> m = new HashMap<>();
        while (st.hasMoreTokens()) {
            String temp;
            temp = st.nextToken();

            if (temp.charAt(0) == 'T' || temp.charAt(0) == 't') {
                if (!m.containsKey(temp)) {
                    m.put(temp, 1);
                } else {
                    int count = m.get(temp);
                    m.put(temp, count + 1);
                }

            }
        }
        System.out.println(Collections.singletonList(m));
    } 
}
