import java.io.*;
import java.util.Scanner;

public class Main {
    static int compare;
    static int toFile;


    public static void Sort(File data, int n) {
        try {
            String str;
            int t = 1;
            //первый проход
            BufferedReader reader0 = new BufferedReader(new FileReader(data));
            BufferedWriter writer0;
            String numb0;
            while ((numb0 = reader0.readLine()) != null) {
                toFile++;
                str = "file" + t + ".txt";
                writer0 = new BufferedWriter(new FileWriter(str, true));
                writer0.write(numb0 + "\n");
                toFile++;
                t++;
                if (t == n + 1) t = 1;
                writer0.close();
            }
            reader0.close();

            //слияние
            int seriesMain = 1;
            int[] seriesNumbs = new int[n];
            String[] numbs = new String[n];
            String file;
            int fReader = 1;
            int fWriter = n + 1;
            BufferedReader[] readers;
            BufferedWriter[] writers;
            File[] files;
            for (; ; ) {
                readers = new BufferedReader[n];
                writers = new BufferedWriter[n];
                files = new File[n];
                for (int i = 0, fR = fReader, fW = fWriter; i < n; i++, fR++, fW++) {
                   // toFile++;
                    file = "file" + fR + ".txt";
                    files[i] = new File(file);
                    readers[i] = new BufferedReader(new FileReader(files[i]));
                    file = "file" + fW + ".txt";
                    writers[i] = new BufferedWriter(new FileWriter(file, true));
                }

                for (int i = 0; ; ) {
                    for (int j = 0; j < n; j++) {
                        numbs[j] = readers[j].readLine();
                        toFile++;
                        compare++;
                        if (numbs[j] == null) {
                            seriesNumbs[j] = seriesMain + 1;
                        } else {
                            seriesNumbs[j] = 1;
                        }
                    }

                    int count = 0;
                    for (int j = 0; j < n; j++) {
                        compare++;
                        if (numbs[j] == null) {
                            count++;
                        }
                    }
                    if (count == n) {
                        break;
                    }

                    for (; ; ) {
                        String minNumb = null;
                        int minIndex = -1;
                        for (int j = 0; j < n; j++) {
                            compare++;
                            if (numbs[j] != null) {
                                minNumb = numbs[j];
                                minIndex = j;
                                break;
                            }
                        }
                        for (int j = minIndex + 1; j < n; j++) {
                            compare++;
                            if (numbs[j] == null) {
                                continue;
                            } else {
                                compare++;
                                
                               /*if (Double.parseDouble(numbs[j]) > Double.parseDouble(minNumb)) {
                                    minNumb = numbs[j];
                                    minIndex = j;
                                }*/
                                if (Double.parseDouble(numbs[j]) < Double.parseDouble(minNumb)) {
                                    minNumb = numbs[j];
                                    minIndex = j;
                                }
                            }
                        }

                        toFile++;
                        writers[i].write(minNumb + "\n");
                        compare++;
                        if (seriesNumbs[minIndex] < seriesMain) {
                            toFile++;
                            numbs[minIndex] = readers[minIndex].readLine();
                            compare++;
                            if (numbs[minIndex] == null) {
                                seriesNumbs[minIndex] = seriesMain + 1;
                            } else {
                                seriesNumbs[minIndex]++;
                            }
                        } else {
                            numbs[minIndex] = null;
                            seriesNumbs[minIndex] = seriesMain + 1;
                        }

                        count = 0;
                        for (int j = 0; j < n; j++) {
                            if (seriesNumbs[j] > seriesMain) {
                                count++;
                            }
                        }
                        if (count == n) {
                            break;
                        }
                    }

                    i++;
                    if (i == n) {
                        i = 0;
                    }
                }

                for (int i = 0; i < n; i++) {
                    writers[i].close();
                    readers[i].close();
                }

                file = "file" + (fWriter + 1) + ".txt";
                BufferedReader readerBuff = new BufferedReader(new FileReader(file));
                toFile++;
                String numbBuff = readerBuff.readLine();
                readerBuff.close();
                if (numbBuff == null) {
                    break;
                }


                seriesMain = seriesMain * n;
                if (fWriter == n + 1) {
                    fWriter = 1;
                } else {
                    fWriter = n + 1;
                }
                if (fReader == n + 1) {
                    fReader = 1;
                } else {
                    fReader = n + 1;
                }
                for (int i = 0, k = fWriter; i < n; i++, k++) {
                    files[i].delete();
                }
            }

            //перезапись
            data.delete();
            file = "file" + fWriter + ".txt";
            BufferedReader readerLast = new BufferedReader(new FileReader(file));
            BufferedWriter writerLast = new BufferedWriter(new FileWriter(data));
            String numbLast;
            while ((numbLast = readerLast.readLine()) != null) {
                writerLast.write(numbLast + "\n");
            }
            readerLast.close();
            writerLast.close();

            for (int i = 1; i <= 2 * n; i++) {
                file = "file" + i + ".txt";
                File fileDel = new File(file);
                fileDel.delete();
            }

        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        int n = 3;
        try {
            File data = new File("data.txt");
            BufferedWriter writer = new BufferedWriter(new FileWriter(data));
            Scanner scan = new Scanner(System.in);
            System.out.println("Введите количество элементов: ");
            int k = scan.nextInt();
            for (int i = 0; i < k; i++) {
                writer.write(String.valueOf(Math.round(Math.random() * 20) - 10) + "\n");
            }
            writer.close();

            double end = 0;
                double start = System.nanoTime();
                Sort(data, n);
                end += System.nanoTime() - start;
            System.out.println("Случайно");
            System.out.println("Время: " + end / 1000000);
            System.out.println("Сравнения: " + compare);
            System.out.println("Обращений к файлам: " + toFile);

            end = 0;
            compare = 0;
            toFile = 0;
                start = System.nanoTime();
                Sort(data, n);
                end += System.nanoTime() - start;
            //System.out.println("По убыванию");
            System.out.println("По возрастанию");
            System.out.println("Время: " + end / 1000000);
            System.out.println("Сравнения: " + compare);
            System.out.println("Обращений к файлам: " + toFile);

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

