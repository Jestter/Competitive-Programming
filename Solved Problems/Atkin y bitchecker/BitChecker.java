/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Jestter
 */
public class BitChecker
{
    int limit;
    int size;
    byte[] table;
    
    public BitChecker(int limit)
    {
        this.limit = limit;
        this.size = ((int)limit/8)+1;
        this.table = new byte[size];
        
        for(int i=0;i<size;i++)
        {
            this.table[i] = 0;
        }
    }
    
    public void check(int n)
    {
        int a = (int)n/8;
        int b = n%8;
        int tmp = table[a] & 0xFF;
        int[] num = new int[8];
        
        for(int i=7;i>=0;i--)
        {
            int exp = (int)Math.pow(2, i);
            num[i] = (int) (tmp/exp);
         
            tmp = (int) (tmp%exp);
        }
       
        num[b] = 1;
        tmp = 0;
        for(int i=7;i>=0;i--)
        {
            int exp = (int)Math.pow(2, i);
            tmp += num[i]* exp;
           
        }
        table[a] = (byte) tmp;
    }
    
    public void uncheck(int n)
    {
        int a = (int)n/8;
        int b = n%8;
        int tmp = table[a] & 0xFF;
        int[] num = new int[8];
        
        for(int i=7;i>=0;i--)
        {
            int exp = (int)Math.pow(2, i);
            num[i] = (int) (tmp/exp);
           
            tmp = (int) (tmp%exp);
        }
        num[b] = 0;
        tmp = 0;
        for(int i=7;i>=0;i--)
        {
            int exp = (int)Math.pow(2, i);
            tmp += num[i]* exp;
           
        }
        table[a] = (byte) tmp;

    }
    
    public void flip(int n)
    {
        int a = (int)n/8;
        int b = n%8;
        int tmp = table[a] & 0xFF;
        int[] num = new int[8];
        
        for(int i=7;i>=0;i--)
        {
            int exp = (int)Math.pow(2, i);
            num[i] = (int) (tmp/exp);
            tmp = (int) (tmp%exp);
        }
        
        if(num[b]==0)num[b] = 1;
        else if(num[b]==1)num[b]=0;
        tmp = 0;
        for(int i=0;i<8;i++)
        {
            int exp = (int)Math.pow(2, i);
            tmp += num[i]* exp;
        }
        table[a] = (byte) tmp;
    }
    
    public boolean isChecked(int n)
    {
        int a = (int)n/8;
        int b = n%8;
        int tmp = table[a] & 0xFF;
        int[] num = new int[8];
        
        for(int i=7;i>=0;i--)
        {
            int exp = (int)Math.pow(2, i);
            num[i] = (int) (tmp/exp);
            tmp = (int) (tmp%exp);
        }
        
        if(num[b]==1)return true;
        else return false;
    }
}
