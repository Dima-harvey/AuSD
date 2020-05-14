import java.util.Scanner;
public class Lab7{	
	static int N=100000000;
	static int[] hashArray= new int[N];
	private static long time=0;
	private static long time1=0;
	private static long begin=0;
	private static long begin1=0;
	public static int hashFunc(int rTo, int key){
		if (key< rTo)
		      return key;
		   else
		  return hashFunc(rTo,key/rTo)*10+key%rTo; 
	}
	public static void insert(int i){
		int index = hashFunc(8,i);

		while(hashArray[index] != 0){
			index++;
			index %= N;
		}
		hashArray[index] = i;
	}
	public static void print(){
		for(int i = 0; i < N; i++)
			if(hashArray[i] != 0)
				System.out.println(hashArray[i] + " ");
		System.out.println();
	}
	
	public static int find(int key){
		int index = hashFunc(8,key);
		while(hashArray[index] != 0){
			if(hashArray[index]==key)
				return index;
			index++;
			index %=N ;
		}
		return -1;
	}
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		System.out.println("Enter max element for HashTable");
		int maxnum=0;
		maxnum=in.nextInt();
		System.out.println("HashTablr element ");
		for(int i=0;i<N;i++) {
			hashArray[i] = 0;
		}
		for(int i=1; i<=maxnum;i++) {
			insert(i);
			if(i==1){
                begin=System.nanoTime();
            }
			if(i==100) {
				time=System.nanoTime()-begin;
			}
            if(i==maxnum-100){
                begin1=System.nanoTime();
            }
		}
		time1=System.nanoTime()-begin1;
		print();
		System.out.println("время добавления первых 100 элементов:"+time/1_000_000.0);
        System.out.println("время добавления последних 100 элементов:"+time1/1_000_000.0);
		System.out.println("Enter element for find ");
		int number=in.nextInt();
		if(number!=0) {
		  begin=System.nanoTime();
		  System.out.println(find(number));
		}
		
		time=System.nanoTime();
		time=time-begin;
        System.out.println("Time for find:"+time/1_000_000.0);

		
	}
}
