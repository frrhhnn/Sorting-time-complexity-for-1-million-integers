# Sorting-time-complexity-for-1-million-integers

Nama : Farhanul Khair

NPM  : 2208107010076

Mata Kuliah : Struktur Data dan Algoritma

Pada tugas kali ini saya telah menyiapkan sebuah program dengan bahasa pemrograman C untuk melakukan pengurutan bilangan secara acak menggunakan tiga algortima yang berbeda yaitu, buble sort, selection sort, dan insertion sort. Kode program ini akan menampilkan nama sorting, jumlah bilangan yang di sorting dan waktu yang diperlukan untuk mensorting bilangan tersebut. Program ini akan mencetak setiap 100 ribu bilangan pada setiap iterasi. Kode program ini disimpan di dalam sebuah file dengan ekstensi .c, dan mengompilasinya menggunakan compiler C seperti GCC. Setelah berhasil dikompilasi, kode program tersebut di jalankan di terminal dengan perintah .\2208107010076_Simple_Sorting.

Hasil eksekusi program ini akan menampilkan waktu yang dibutuhkan untuk setiap algoritma pengurutan dalam milidetik (ms). Selain itu, program ini akan membuat sebuah file txt bernama unsorted.txt yang berisikan bilangan yang sudah digenerate terlebih dahulu dan dalam bentuk tidak berurutan.

Dalam kode program di atas, terdapat beberapa fungsi yang digunakan, di antaranya:

- void generateRandomNumbers(int array[], int size): Fungsi ini digunakan untuk mengisi array dengan bilangan bulat acak menggunakan fungsi rand() dari library <stdlib.h>. Seed untuk fungsi rand() diinisialisasi dengan waktu saat ini menggunakan srand(time(NULL)).
- void bubbleSort(int array[], int size): Fungsi ini mengurutkan array menggunakan algoritma bubble sort. Algoritma ini membandingkan dua elemen yang bersebelahan dan menukar posisinya jika tidak dalam urutan yang benar, secara berulang hingga seluruh array terurut.
- void selectionSort(int array[], int size): Fungsi ini mengurutkan array menggunakan algoritma selection sort. Algoritma ini mencari elemen terkecil dari array yang belum terurut dan menukarnya dengan elemen pertama dari array yang belum terurut, secara berulang hingga seluruh array terurut.
- void insertionSort(int array[], int size): Fungsi ini mengurutkan array menggunakan algoritma insertion sort. Algoritma ini membandingkan setiap elemen dengan elemen di sebelah kirinya, lalu memindahkan elemen tersebut ke posisi yang tepat dalam array yang sudah terurut, secara berulang hingga seluruh array terurut.
- void saveArrayToFile(int array[], int size): Fungsi ini menyimpan isi array ke dalam file "unsorted.txt". Setiap elemen array disimpan dalam baris baru dalam file tersebut menggunakan fungsi fprintf() dari library <stdio.h>. Data yang diacak dan disimpan ke dalam file ini adalah sebanyak 1 juta data.

Link youtube penjelasan kode dan cara menjalankan kode: https://youtu.be/0hW5I8qZx3Q
