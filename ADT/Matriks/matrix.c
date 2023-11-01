/* ********** Definisi TYPE Matrix dengan Index dan elemen integer ********** */

#include "../Boolean/boolean.h"
#include "matrix.h"
#include <stdlib.h>
#include <stdio.h>

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matrix *** */
void matrix_createMatrix(int nRows, int nCols, Matrix *m)
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
boolean matrix_isMatrixIdxValid(int i, int j)
{
   return (i >= 0 && i < ROW_CAP) && (j >= 0 && j < COL_CAP);
}
/* Mengirimkan true jika i, j adalah index yang valid untuk matriks apa pun */

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
IdxType matrix_getLastIdxRow(Matrix m)
{
   return ROW_EFF(m)-1;
}
/* Mengirimkan Index baris terbesar m */
IdxType matrix_getLastIdxCol(Matrix m)
{
   return COL_EFF(m)-1;
}
/* Mengirimkan Index kolom terbesar m */
boolean matrix_isIdxEff(Matrix m, IdxType i, IdxType j)
{
   return (i >= 0) && (i < ROW_EFF(m)) && (j >= 0) && (j < COL_EFF(m));
}
/* Mengirimkan true jika i, j adalah Index efektif bagi m */
ElType matrix_getElmtDiagonal(Matrix m, IdxType i)
{
   return ELMT(m,i,i);
}
/* Mengirimkan elemen m(i,i) */

/* ********** Assignment  Matrix ********** */
void matrix_copyMatrix(Matrix mIn, Matrix *mOut)
{
   matrix_createMatrix(ROW_EFF(mIn), COL_EFF(mIn), mOut);
   int i = 0;
   for(i = 0;i < ROW_EFF(mIn); i++)
   {
      int j = 0;
      for(j = 0;j < COL_EFF(mIn); j++)
      {
         ELMT(*mOut,i,j) = ELMT(mIn,i,j);
      }
   }
}
/* Melakukan assignment mOut <- mIn */

/* ********** KELOMPOK BACA/TULIS ********** */
void matrix_readMatrix(Matrix *m, int nRow, int nCol)
{
   matrix_createMatrix(nRow,nCol,m);

   int i = 0;
   for(i = 0;i < ROW_EFF(*m); i++)
   {
      int j = 0;
      for(j = 0;j < COL_EFF(*m); j++)
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
void matrix_displayMatrix(Matrix m)
{
   int i = 0;
   for(i = 0;i < ROW_EFF(m); i++)
   {
      int j = 1;
      printf("%d", ELMT(m,i,0));
      for(j = 1;j < COL_EFF(m); j++)
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
Matrix matrix_addMatrix(Matrix m1, Matrix m2)
{
   Matrix m3;
   matrix_createMatrix(ROW_EFF(m1), COL_EFF(m1), &m3);
   int i = 0;
   for(i = 0;i < ROW_EFF(m1); i++)
   {
      int j = 0;
      for(j = 0;j < COL_EFF(m1); j++)
      {
         ELMT(m3,i,j) = ELMT(m1,i,j) + ELMT(m2,i,j);
      }
   }
   return m3;
}
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil penjumlahan matriks: m1 + m2 */
Matrix matrix_subtractMatrix(Matrix m1, Matrix m2)
{
   Matrix m3;
   matrix_createMatrix(ROW_EFF(m1), COL_EFF(m2), &m3);
   int i = 0;
   for(i = 0;i < ROW_EFF(m1); i++)
   {
      int j = 0;
      for(j = 0;j < COL_EFF(m1); j++)
      {
         ELMT(m3,i,j) = ELMT(m1,i,j) - ELMT(m2,i,j);
      }
   }
   return m3;
}
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil pengurangan matriks: salinan m1 – m2 */
Matrix matrix_multiplyMatrix(Matrix m1, Matrix m2)
{
   Matrix m3;
   matrix_createMatrix(ROW_EFF(m1), COL_EFF(m2), &m3);
   int i = 0;
   for(i = 0;i < ROW_EFF(m1); i++)
   {
      int j = 0;
      for(j = 0;j < COL_EFF(m2); j++)
      {
         int k = 0;
         int total = 0;
         for(k = 0;k < COL_EFF(m1); k++)
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
Matrix matrix_multiplyMatrixWithMod(Matrix m1,Matrix m2,int mod)
{
   Matrix m3;
   matrix_createMatrix(ROW_EFF(m1), COL_EFF(m2), &m3);
   int i = 0;
   for(i = 0;i < ROW_EFF(m1); i++)
   {
      int j = 0;
      for(j = 0;j < COL_EFF(m2); j++)
      {
         int k = 0;
         int total = 0;
         for(k = 0;k < COL_EFF(m1); k++)
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
Matrix matrix_multiplyByConst(Matrix m, ElType x)
{
   Matrix m3;
   matrix_createMatrix(ROW_EFF(m), COL_EFF(m), &m3);
   int i = 0;
   for(i = 0;i < ROW_EFF(m); i++)
   {
      int j = 0;
      for(j = 0;j < COL_EFF(m); j++)
      {
         ELMT(m3,i,j) = ELMT(m,i,j) * x;
      }
   }
   return m3;
}
/* Mengirim hasil perkalian setiap elemen m dengan x */
void matrix_pMultiplyByConst(Matrix *m, ElType k)
{
   int i = 0;
   for(i = 0;i < ROW_EFF(*m); i++)
   {
      int j = 0;
      for(j = 0;j < COL_EFF(*m); j++)
      {
         ELMT(*m,i,j) *= k;
      }
   }
}
/* I.S. m terdefinisi, k terdefinisi */
/* F.S. Mengalikan setiap elemen m dengan k */

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP Matrix ********** */
boolean matrix_isMatrixEqual(Matrix m1, Matrix m2)
{
   if(!(matrix_getLastIdxCol(m1) == matrix_getLastIdxCol(m2) && matrix_getLastIdxRow(m1) == matrix_getLastIdxRow(m2))) return false;

   int i = 0;
   for(i = 0;i < ROW_EFF(m1); i++)
   {
      int j = 0;
      for(j = 0;j < COL_EFF(m1); j++)
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
boolean matrix_isMatrixNotEqual(Matrix m1, Matrix m2)
{
   return !matrix_isMatrixEqual(m1, m2);
}
/* Mengirimkan true jika m1 tidak sama dengan m2 */
boolean matrix_isMatrixSizeEqual(Matrix m1, Matrix m2)
{
   return (ROW_EFF(m1) == ROW_EFF(m2) && COL_EFF(m1) == COL_EFF(m2));
}
/* Mengirimkan true jika ukuran efektif matriks m1 sama dengan ukuran efektif m2 */
/* yaitu RowEff(m1) = RowEff (m2) dan ColEff (m1) = ColEff (m2) */

/* ********** Operasi lain ********** */
int matrix_countElmt(Matrix m)
{
   return ROW_EFF(m) * COL_EFF(m);
}
/* Mengirimkan banyaknya elemen m */

/* ********** KELOMPOK TEST TERHADAP Matrix ********** */
boolean matrix_isSquare(Matrix m)
{
   return ROW_EFF(m) == COL_EFF(m);
}
/* Mengirimkan true jika m adalah matriks dg ukuran baris dan kolom sama */
boolean matrix_isSymmetric(Matrix m)
{
   if(!matrix_isSquare(m)) return false;
   int i = 0;
   for(i = 0;i < ROW_EFF(m); i++)
   {
      int j = 0;
      for(j = 0;j < COL_EFF(m); j++)
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
boolean matrix_isIdentity(Matrix m)
{
   if(!matrix_isSquare(m)) return false;
   int i = 0;
   for(i = 0;i < ROW_EFF(m); i++)
   {
      int j = 0;
      for(j = 0;j < COL_EFF(m); j++)
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
boolean matrix_isSparse(Matrix m)
{
   int count0 = 0;
   int i = 0;
   for(i = 0;i < ROW_EFF(m); i++)
   {
      int j = 0;
      for(j = 0;j < COL_EFF(m); j++)
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
Matrix matrix_negation(Matrix m)
{
   return matrix_multiplyByConst(m, -1);
}
/* Menghasilkan salinan m dengan setiap elemen dinegasikan (dikalikan -1) */
void matrix_pNegation(Matrix *m)
{
   matrix_pMultiplyByConst(m, -1);
}
/* I.S. m terdefinisi */
/* F.S. m di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
int matrix_power(int a, int x) {
   int result = 1;
   int i = 0;
   for(i = 0; i < x; i++) {
      result *= a;
   }
   return result;
}
float matrix_determinant(Matrix m)
{
   if(COL_EFF(m) == 1 && ROW_EFF(m) == 1) return ELMT(m,0,0);
   else if(ROW_EFF(m) == 2) {
      return ELMT(m,0,0)*ELMT(m,1,1) - ELMT(m,0,1)*ELMT(m,1,0);
   }
   int i = 0; // baris yang dipilih. Diganti selain 0 harusnya aman.
   int j = 0;
   float total = 0;
   for(j = 0; j < ROW_EFF(m); j++) {
         
      // Bikin matrix kecilnya
      Matrix subM;
      matrix_createMatrix(ROW_EFF(m)-1, COL_EFF(m)-1, &subM);
      int k = 0;
      for(k = 0; k < ROW_EFF(subM); k++) {
         int l = 0;
         for(l = 0; l < ROW_EFF(subM); l++) {
            if(k >= i && l >= j) ELMT(subM,k,l) = ELMT(m,k+1,l+1);
            else if(k >= i) ELMT(subM,k,l) = ELMT(m,k+1,l);
            else if(l >= j) ELMT(subM,k,l) = ELMT(m,k,l+1);
            else ELMT(subM,k,l) = ELMT(m,k,l);
         }
      }
      total += matrix_power(-1, j) * ELMT(m,i,j) * matrix_determinant(subM);
   }

   return total;
}
/* Prekondisi: isSquare(m) */
/* Menghitung nilai determinan m */
Matrix matrix_transpose(Matrix m)
{
   Matrix m1;
   matrix_createMatrix(ROW_EFF(m), COL_EFF(m), &m1);
   int i = 0;
   for(i = 0;i < ROW_EFF(m); i++)
   {
      int j = 0;
      for(j = 0;j < COL_EFF(m); j++)
      {
         ELMT(m1,i,j) = ELMT(m,j,i);
      }
   }
   return m1;
}
/* I.S. m terdefinisi dan IsSquare(m) */
/* F.S. menghasilkan salinan transpose dari m, yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */
void matrix_pTranspose(Matrix *m)
{
   Matrix m1;
   matrix_copyMatrix(*m, &m1);
   int i = 0;
   for(i = 0;i < ROW_EFF(*m); i++)
   {
      int j = 0;
      for(j = 0;j < COL_EFF(*m); j++)
      {
         ELMT(*m,i,j) = ELMT(m1,j,i);
      }
   }
}
/* I.S. m terdefinisi dan IsSquare(m) */
/* F.S. m "di-transpose", yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */

