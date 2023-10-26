/* ********** Definisi TYPE Matrix dengan Index dan elemen integer ********** */

#ifndef MATRIX_H
#define MATRIX_H

#include "boolean.h"
#include <stdlib.h>
#include <stdio.h>

/* Ukuran maksimum baris dan kolom */
#define ROW_CAP 100
#define COL_CAP 100

typedef int IdxType; /* Index baris, kolom */
typedef int ElType;
typedef struct
{
   ElType mem[ROW_CAP][COL_CAP];
   int rowEff; /* banyaknya/ukuran baris yg terdefinisi */
   int colEff; /* banyaknya/ukuran kolom yg terdefinisi */
} Matrix;
/* rowEff >= 1 dan colEff >= 1 */
/* Indeks matriks yang digunakan: [0..ROW_CAP-1][0..COL_CAP-1] */
/* Memori matriks yang dipakai selalu di "ujung kiri atas" */

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matrix *** */
void createMatrix(int nRows, int nCols, Matrix *m)
{
   (*m).rowEff = nRows;
   (*m).colEff = nCols;
}
/* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */

/* *** Selektor *** */
#define ROW_EFF(M) (M).rowEff
#define COL_EFF(M) (M).colEff
#define ELMT(M, i, j) (M).mem[(i)][(j)]

/* *** Selektor "Dunia Matrix" *** */
boolean isMatrixIdxValid(int i, int j)
{
   return (i >= 0 && i < ROW_CAP) && (j >= 0 && j < COL_CAP);
}
/* Mengirimkan true jika i, j adalah index yang valid untuk matriks apa pun */

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
IdxType getLastIdxRow(Matrix m)
{
   return ROW_EFF(m)-1;
}
/* Mengirimkan Index baris terbesar m */
IdxType getLastIdxCol(Matrix m)
{
   return COL_EFF(m)-1;
}
/* Mengirimkan Index kolom terbesar m */
boolean isIdxEff(Matrix m, IdxType i, IdxType j)
{
   return (i >= 0) && (i < ROW_EFF(m)) && (j >= 0) && (j < COL_EFF(m));
}
/* Mengirimkan true jika i, j adalah Index efektif bagi m */
ElType getElmtDiagonal(Matrix m, IdxType i)
{
   return ELMT(m,i,i);
}
/* Mengirimkan elemen m(i,i) */

/* ********** Assignment  Matrix ********** */
void copyMatrix(Matrix mIn, Matrix *mOut)
{
   createMatrix(ROW_EFF(mIn), COL_EFF(mIn), mOut);
   int i = 0;
   for(i;i < ROW_EFF(mIn); i++)
   {
      int j = 0;
      for(j;j < COL_EFF(mIn); j++)
      {
         ELMT(*mOut,i,j) = ELMT(mIn,i,j);
      }
   }
}
/* Melakukan assignment mOut <- mIn */

/* ********** KELOMPOK BACA/TULIS ********** */
void readMatrix(Matrix *m, int nRow, int nCol)
{
   createMatrix(nRow,nCol,m);

   int i = 0;
   for(i;i < ROW_EFF(*m); i++)
   {
      int j = 0;
      for(j;j < COL_EFF(*m); j++)
      {
         int n;
         scanf("%d", &n);
         ELMT(*m,i,j) = n;
      }
   }
}
/* I.S. isIdxValid(nRow,nCol) */
/* F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol */
/* Proses: Melakukan CreateMatrix(m,nRow,nCol) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika nRow = 3 dan nCol = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
*/
void displayMatrix(Matrix m)
{
   int i = 0;
   for(i;i < ROW_EFF(m); i++)
   {
      int j = 1;
      printf("%d", ELMT(m,i,0));
      for(j;j < COL_EFF(m); j++)
      {
         printf(" %d", ELMT(m,i,j));
      }

      // disuruh ga ada new line di akhir rupanya harus ada. 
      // if( !(i == ROW_EFF(m)-1 && j == COL_EFF(m)) ) // gak -1 karena ada j++ di dalam for loop
         printf("\n");
   }
}
/* I.S. m terdefinisi */
/* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi. Baris terakhir tidak diakhiri dengan newline */
/* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
Matrix addMatrix(Matrix m1, Matrix m2)
{
   Matrix m3;
   createMatrix(ROW_EFF(m1), COL_EFF(m1), &m3);
   int i = 0;
   for(i;i < ROW_EFF(m1); i++)
   {
      int j = 0;
      for(j;j < COL_EFF(m1); j++)
      {
         ELMT(m3,i,j) = ELMT(m1,i,j) + ELMT(m2,i,j);
      }
   }
   return m3;
}
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil penjumlahan matriks: m1 + m2 */
Matrix subtractMatrix(Matrix m1, Matrix m2)
{
   Matrix m3;
   createMatrix(ROW_EFF(m1), COL_EFF(m2), &m3);
   int i = 0;
   for(i;i < ROW_EFF(m1); i++)
   {
      int j = 0;
      for(j;j < COL_EFF(m1); j++)
      {
         ELMT(m3,i,j) = ELMT(m1,i,j) - ELMT(m2,i,j);
      }
   }
   return m3;
}
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil pengurangan matriks: salinan m1 – m2 */
Matrix multiplyMatrix(Matrix m1, Matrix m2)
{
   Matrix m3;
   createMatrix(ROW_EFF(m1), COL_EFF(m2), &m3);
   int i = 0;
   for(i;i < ROW_EFF(m1); i++)
   {
      int j = 0;
      for(j;j < COL_EFF(m2); j++)
      {
         int k = 0;
         int total = 0;
         for(k;k < COL_EFF(m1); k++)
         {
            total += ELMT(m1,i,k) * ELMT(m2,k,j);

         }
         ELMT(m3,i,j) = total;
      }
   }
   return m3;
}
/* Prekondisi : Ukuran kolom efektif m1 = ukuran baris efektif m2 */
/* Mengirim hasil perkalian matriks: salinan m1 * m2 */
Matrix multiplyMatrixWithMod(Matrix m1,Matrix m2,int mod)
{
   Matrix m3;
   createMatrix(ROW_EFF(m1), COL_EFF(m2), &m3);
   int i = 0;
   for(i;i < ROW_EFF(m1); i++)
   {
      int j = 0;
      for(j;j < COL_EFF(m2); j++)
      {
         int k = 0;
         int total = 0;
         for(k;k < COL_EFF(m1); k++)
         {
            total += ELMT(m1,i,k) * ELMT(m2,k,j);

         }
         ELMT(m3,i,j) = total %  mod;
      }
   }
   return m3;
}
/* Prekondisi : Ukuran kolom efektif m1 = ukuran baris efektif m2 */
/* Mengirim hasil perkalian matriks: salinan (m1 * m2)%mod, artinya setiap elemen matrix hasil perkalian m1 * m2 dilakukan modulo terhadap mod */
Matrix multiplyByConst(Matrix m, ElType x)
{
   Matrix m3;
   createMatrix(ROW_EFF(m), COL_EFF(m), &m3);
   int i = 0;
   for(i;i < ROW_EFF(m); i++)
   {
      int j = 0;
      for(j;j < COL_EFF(m); j++)
      {
         ELMT(m3,i,j) = ELMT(m,i,j) * x;
      }
   }
   return m3;
}
/* Mengirim hasil perkalian setiap elemen m dengan x */
void pMultiplyByConst(Matrix *m, ElType k)
{
   int i = 0;
   for(i;i < ROW_EFF(*m); i++)
   {
      int j = 0;
      for(j;j < COL_EFF(*m); j++)
      {
         ELMT(*m,i,j) *= k;
      }
   }
}
/* I.S. m terdefinisi, k terdefinisi */
/* F.S. Mengalikan setiap elemen m dengan k */

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP Matrix ********** */
boolean isMatrixEqual(Matrix m1, Matrix m2)
{
   if(!(getLastIdxCol(m1) == getLastIdxCol(m2) && getLastIdxRow(m1) == getLastIdxRow(m2))) return false;

   int i = 0;
   for(i;i < ROW_EFF(m1); i++)
   {
      int j = 0;
      for(j;j < COL_EFF(m1); j++)
      {
         if(ELMT(m1,i,j) != ELMT(m2,i,j))
         {
            return false;
         }
      }
   }
   return true;
}
/* Mengirimkan true jika m1 = m2, yaitu count(m1) = count(m2) dan */
/* untuk setiap i,j yang merupakan Index baris dan kolom m1(i,j) = m2(i,j) */
/* Juga merupakan strong eq karena getLastIdxCol(m1) = getLastIdxCol(m2) */
boolean isMatrixNotEqual(Matrix m1, Matrix m2)
{
   return !isMatrixEqual(m1, m2);
}
/* Mengirimkan true jika m1 tidak sama dengan m2 */
boolean isMatrixSizeEqual(Matrix m1, Matrix m2)
{
   return (ROW_EFF(m1) == ROW_EFF(m2) && COL_EFF(m1) == COL_EFF(m2));
}
/* Mengirimkan true jika ukuran efektif matriks m1 sama dengan ukuran efektif m2 */
/* yaitu RowEff(m1) = RowEff (m2) dan ColEff (m1) = ColEff (m2) */

/* ********** Operasi lain ********** */
int countElmt(Matrix m)
{
   return ROW_EFF(m) * COL_EFF(m);
}
/* Mengirimkan banyaknya elemen m */

/* ********** KELOMPOK TEST TERHADAP Matrix ********** */
boolean isSquare(Matrix m)
{
   return ROW_EFF(m) == COL_EFF(m);
}
/* Mengirimkan true jika m adalah matriks dg ukuran baris dan kolom sama */
boolean isSymmetric(Matrix m)
{
   if(!isSquare(m)) return false;
   int i = 0;
   for(i;i < ROW_EFF(m); i++)
   {
      int j = 0;
      for(j;j < COL_EFF(m); j++)
      {
         if(ELMT(m,i,j) != ELMT(m,j,i))
         {
            return false;
         }
      }
   }
   return true;
}
/* Mengirimkan true jika m adalah matriks simetri : isSquare(m) 
   dan untuk setiap elemen m, m(i,j)=m(j,i) */
boolean isIdentity(Matrix m)
{
   if(!isSquare(m)) return false;
   int i = 0;
   for(i;i < ROW_EFF(m); i++)
   {
      int j = 0;
      for(j;j < COL_EFF(m); j++)
      {
         if( !( (ELMT(m,i,j) == 0 && (i != j)) || (ELMT(m,i,j) == 1 && (i == j)) ) )
         {
            return false;
         }
      }
   }
   return true;
}
/* Mengirimkan true jika m adalah matriks satuan: isSquare(m) dan 
   setiap elemen diagonal m bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
boolean isSparse(Matrix m)
{
   int count0 = 0;
   int i = 0;
   for(i;i < ROW_EFF(m); i++)
   {
      int j = 0;
      for(j;j < COL_EFF(m); j++)
      {
         if(ELMT(m,i,j) == 0)
         {
            count0++;
         }
      }
   }
   int totalElmt = ROW_EFF(m) * COL_EFF(m);
   return (1 - (float)count0/(float)totalElmt) <= 0.05;
}
/* Mengirimkan true jika m adalah matriks sparse: matriks “jarang” dengan definisi: 
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
Matrix negation(Matrix m)
{
   return multiplyByConst(m, -1);
}
/* Menghasilkan salinan m dengan setiap elemen dinegasikan (dikalikan -1) */
void pNegation(Matrix *m)
{
   pMultiplyByConst(m, -1);
}
/* I.S. m terdefinisi */
/* F.S. m di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
int power(int a, int x) {
   int result = 1;
   int i = 0;
   for(i; i < x; i++) {
      result *= a;
   }
   return result;
}
float determinant(Matrix m)
{
   if(COL_EFF(m) == 1 & ROW_EFF(m) == 1) return ELMT(m,0,0);
   else if(ROW_EFF(m) == 2) {
      return ELMT(m,0,0)*ELMT(m,1,1) - ELMT(m,0,1)*ELMT(m,1,0);
   }
   int i = 0; // baris yang dipilih. Diganti selain 0 harusnya aman.
   int j = 0;
   float total = 0;
   for(j; j < ROW_EFF(m); j++) {
         
      // Bikin matrix kecilnya
      Matrix subM;
      createMatrix(ROW_EFF(m)-1, COL_EFF(m)-1, &subM);
      int k = 0;
      for(k; k < ROW_EFF(subM); k++) {
         int l = 0;
         for(l; l < ROW_EFF(subM); l++) {
            if(k >= i && l >= j) ELMT(subM,k,l) = ELMT(m,k+1,l+1);
            else if(k >= i) ELMT(subM,k,l) = ELMT(m,k+1,l);
            else if(l >= j) ELMT(subM,k,l) = ELMT(m,k,l+1);
            else ELMT(subM,k,l) = ELMT(m,k,l);
         }
      }
      total += power(-1, j) * ELMT(m,i,j) * determinant(subM);
   }

   return total;
}
/* Prekondisi: isSquare(m) */
/* Menghitung nilai determinan m */
Matrix transpose(Matrix m)
{
   Matrix m1;
   createMatrix(ROW_EFF(m), COL_EFF(m), &m1);
   int i = 0;
   for(i;i < ROW_EFF(m); i++)
   {
      int j = 0;
      for(j;j < COL_EFF(m); j++)
      {
         ELMT(m1,i,j) = ELMT(m,j,i);
      }
   }
   return m1;
}
/* I.S. m terdefinisi dan IsSquare(m) */
/* F.S. menghasilkan salinan transpose dari m, yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */
void pTranspose(Matrix *m)
{
   Matrix m1;
   copyMatrix(*m, &m1);
   int i = 0;
   for(i;i < ROW_EFF(*m); i++)
   {
      int j = 0;
      for(j;j < COL_EFF(*m); j++)
      {
         ELMT(*m,i,j) = ELMT(m1,j,i);
      }
   }
}
/* I.S. m terdefinisi dan IsSquare(m) */
/* F.S. m "di-transpose", yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */

#endif