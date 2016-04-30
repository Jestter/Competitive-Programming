/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Jestter
 */
public class InputGenTwoSubstrings
{
    public static void main(String[] args)
    {
        new InputGenTwoSubstrings();
    }

    public InputGenTwoSubstrings()
    {
        for (int i = 0; i < 1000; i++)
        {
            int a = (int) (Math.random()*20)+1;
            String s="";
            for (int j = 0; j < a; j++)
            {
                s=s+((char)(int)('A'+Math.random()*('B'-'A'+1)));
            }
            System.out.println(s);
        }
    }
    
    
}
