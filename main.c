#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <assert.h>
#include<conio.h>

    char GJ[][20]={"Rice/Paddy","Greengram","Maize","Wheat","Gram","Pulses"};
    char UP[][20]={"Rice/Paddy","Greengram","Redgram/Arhar","Masur/Lentil","Wheat","Peas","Chick Pea","Blackgram/Urd","Gram",};
    char WB[][20]={"Rice/Paddy","Greengram","Redgram/Arhar","Masur/Lentil","Wheat","Gram","Pulses","Blackgram/Urd"};
    double Profit_GJ[]={50975,18976,20800,15390,18000,22000};
    double Profit_UP[]={50975,18976,29261,21138,15390,4108,17000,19000,18000};
    double Profit_WB[]={50975,18976,29261,21138,15390,18000,22000,19000};
    double Cost_GJ[]={17000,13778,15200,19000,15136,9000};
    double Cost_UP[]={17000,13778,14047,15824,19000,6100,111700,15136,15136};
    double Cost_WB[]={17000,13778,14047,15824,19000,15136,9000,15136};
    int up=10,gj=7,wb=9,NOC=0;
    int cho=0,check=0;
    float area=0;
    double budget=0;


void ShowStates()
{

    printf("        WELCOME TO THE LAND PARTITIONER \n\n\n        KINDLY CHOOSE FROM THE FOLLOWING STATES\n\n ");
    xyz:
    printf("1)UTTAR PRADESH\n 2)WEST BENGAL\n 3)GUJRAT\n CHOICE:");
    scanf("%d",&cho);

    switch(cho)
    {
        case 1: for(int i=0;i<=8;i++)
                 {
                     printf("%d)",i+1);   
                 printf("%s\n",UP[i]);
                 }
                 NOC=up;
                 break;
        case 2: for(int i=0;i<=7;i++)
                 {
                     printf("%d)",i+1);   
                 printf("%s\n",WB[i]);
                 }NOC=wb;
                  break;
        case 3: for(int i=0;i<=5;i++)
                 {
                     printf("%d)",i+1);   
                 printf("%s\n",GJ[i]);
                 }NOC=gj;
                 break;         

       
        default: printf("WRONG INPUT\n");
        goto xyz;
    }
    printf("ENTER LAND AREA MEASUREMENT IN ACRE \n");
    scanf("%f",&area);
            if(area<0.162)
        {
            UP[0][20]=NULL;
            WB[0][20]=NULL;
            GJ[0][20]=NULL;
            printf("RICE HAS BEEN OMITTED DUE TO INSUFFICIENT AREA\n\n");
        }
        switch(cho)
        {
            case 1: for(int i=0;i<9;i++)
            {

            }
        }
        printf("Enter your budget in Rs. :");
        scanf("%lf",&budget);
        printf("\n\n");
         ShowOmitScreen(cho);
    return cho;
}
    


void ShowOmitScreen(int cho)
{
    int o=0,*ptr,i=0,j=0;
    char ch; 
    printf("ANY PARTICULAR CROPS TO OMIT?\n\n");
    printf("\nPRESS 'Y' FOR YES & 'N' FOR NO:");
    scanf("%s",&ch);
    if(ch=='y'||ch=='Y')
    {
        printf("ENTER THE NUMBER OF CROPS TO OMIT");
        scanf("%d",&o);//3
        abc:

        ptr = (int*) calloc(o, sizeof(int));
        if(ptr == NULL)
        {
        printf("Error! memory not allocated.");
        exit(0);
        }
        printf("Enter crop serial no.: ");
        for(i = 0; i < o; ++i)
        {
        scanf("%d", ptr + i);
        }
        switch(cho)
        {
            case 1: for(i = 0; i < o; ++i)
                    {

                        if(*(ptr+i)<10 && *(ptr+i)>0)
                        {
                        UP[*(ptr+i)-2][20]=NULL;
                        Profit_UP[*(ptr+i)-1]=0;
                        Cost_UP[*(ptr+i)-1]=0;
                        }
                        else
                        {
                        printf("INVALID INPUT TRY AGAIN\n\n");
                        free(ptr);
                        goto abc; 
                        }
 
                    }
                    for(int i=0;i<=8;i++)
                    {
                    printf("%d)",i+1);   
                    printf("%s\n",UP[i]);
                    }
                    NOC=up-o;
                    break;

            case 2: for(i = 0; i < o; ++i)
                    {
                       if(*(ptr+i)<7 && *(ptr+i)>0)
                        {
                        WB[*(ptr+i)-2][20]=NULL;
                        Profit_WB[*(ptr+i)-1]=0;
                        Cost_WB[*(ptr+i)-1]=0;
                        }
                        else
                        {
                        printf("INVALID INPUT TRY AGAIN\n\n");
                        free(ptr);
                        goto abc; 
                        }
 
                    }
                    for(int i=0;i<=5;i++)
                    {
                    printf("%d)",i+1);   
                    printf("%s\n",WB[i]);
                    }
                    NOC=wb-o;
                    break;

            case 3: for(i = 0; i < o; ++i)
                    {
                       if(*(ptr+i)<9 && *(ptr+i)>0)
                        {
                        GJ[*(ptr+i)-1][20]=NULL;
                        Profit_GJ[*(ptr+i)-1]=0;
                        Cost_GJ[*(ptr+i)-1]=0;
                        }
                        else
                        {
                        printf("INVALID INPUT TRY AGAIN\n\n");
                        free(ptr);
                        goto abc; 
                        }
 
                    }
                    for(int i=0;i<=7;i++)
                    {
                     printf("%d)",i+1);   
                     printf("%s\n",GJ[i]);
                    }
                    NOC=gj-o;
                    break;
        }          

         free(ptr);
    }

}
#define M 20
#define N 20
static const double epsilon   = 1.0e-8;
int equal(double a, double b) { return fabs(a-b) < epsilon; }

typedef struct {
  int m, n; // m=rows, n=columns, mat[m x n]
  double mat[M][N];
} Tableau;
void nl(int k){ int j; for(j=0;j<k;j++) putchar('-'); putchar('\n'); }

Tableau tab;
void TableauInput()
{ check++;
  int i=0,j=0,p=0,c=0;
          float MAPC=0;             //Max area per crop
          if(NOC>3)
          MAPC=((area*25)/100); 
          else if(NOC>=2)
          MAPC=((area*50)/100);
          else
          MAPC=area;
    tab.m=2+NOC;
  tab.n=NOC;
  tab.mat[0][0]=0;
  tab.mat[1][0]=area;
  tab.mat[2][0]=budget;
    for(i=3;i<tab.m;i++)
    tab.mat[i][0]=MAPC;
  for(i=0;i<tab.m;i++)
  {
    for(j=1;j<NOC;j++)
    {
      if(i==0)
      {
        switch(cho)
        {
        case 1:
        while(Profit_UP[p]==0)
                {
                  p++;
                }
        tab.mat[i][j]=-Profit_UP[p];
        p++;
        break;
        case 2: while(Profit_WB[p]==0)
                {
                  p++;
                }
        tab.mat[i][j]=-Profit_WB[p];
        p++;
        break;
        case 3: while(Profit_GJ[p]==0)
                {
                  p++;
                }
        tab.mat[i][j]=-Profit_GJ[p];
        p++;
        break;
        }
      }
      else if(i==1)
      {
          tab.mat[i][j]=1;
      }
      else if(i==2)
      {
        switch(cho)
        {
        case 1: while(Cost_UP[c]==0)
                {
                  c++;
                }
        tab.mat[i][j]=Cost_UP[c];
        c++;
        break;
        case 2: while(Cost_WB[c]==0)
                {
                  c++;
                }
        tab.mat[i][j]=Cost_WB[c];
        c++;
        break;
        case 3: while(Cost_GJ[c]==0)
                {
                  c++;
                }
        tab.mat[i][j]=Cost_GJ[c];
        c++;
        break;
        }
        
      }
      else
      {
          int k=1;
        for(i=3;i<tab.m;i++)
        {
            for(j=1;j<NOC;j++)
            {
                if(j==k)
                tab.mat[i][j]=1;
                else
                tab.mat[i][j]=0;
                
            }
            k++;
        }

          
      }
      
      
    }
   }
}  
void read_tableau(Tableau *tab, const char * filename) {
  int err, i, j;
  FILE * fp;

  fp  = fopen(filename, "r" );
  if( !fp ) {
    printf("Cannot read %s\n", filename); exit(1);
  }
  memset(tab, 0, sizeof(*tab));
  err = fscanf(fp, "%d %d", &tab->m, &tab->n);
  if (err == 0 || err == EOF) {
    printf("Cannot read m or n\n"); exit(1);
  }
  for(i=0;i<tab->m; i++) {
    for(j=0;j<tab->n; j++) {
      err = fscanf(fp, "%lf", &tab->mat[i][j]);
      if (err == 0 || err == EOF) {
        printf("Cannot read A[%d][%d]\n", i, j); exit(1);
      }
    }
  }
  printf("Read tableau [%d rows x %d columns] from file '%s'.\n",
    tab->m, tab->n, filename);
  fclose(fp);
}

void print_tableau(Tableau *tab, const char* mes) {
  static int counter=0;
  int i, j;
  printf("\n%d. Tableau %s:\n", ++counter, mes);
  nl(70);

  printf("%-6s%5s", "col:", "b[i]");
  for(j=1;j<tab->n; j++) { printf("    x%d,", j); } printf("\n");

  for(i=0;i<tab->m; i++) {
    if (i==0) printf("max:"); else
    printf("b%d: ", i);
    for(j=0;j<tab->n; j++) {
      if (equal((int)tab->mat[i][j], tab->mat[i][j]))
        printf(" %6d", (int)tab->mat[i][j]);
      else
        printf(" %6.2lf", tab->mat[i][j]);
      }
    printf("\n");
  }
  nl(70);
}


void pivot_on(Tableau *tab, int row, int col) {
  int i, j;
  double pivot;

  pivot = tab->mat[row][col];
  assert(pivot>0);
  for(j=0;j<tab->n;j++)
    tab->mat[row][j] /= pivot;
  assert( equal(tab->mat[row][col], 1. ));

  for(i=0; i<tab->m; i++) { // foreach remaining row i do
    double multiplier = tab->mat[i][col];
    if(i==row) continue;
    for(j=0; j<tab->n; j++) { // r[i] = r[i] - z * r[row];
      tab->mat[i][j] -= multiplier * tab->mat[row][j];
    }
  }
}

// Find pivot_col = most negative column in mat[0][1..n]
int find_pivot_column(Tableau *tab) {
  int j, pivot_col = 1;
  double lowest = tab->mat[0][pivot_col];
  for(j=1; j<tab->n; j++) {
    if (tab->mat[0][j] < lowest) {
      lowest = tab->mat[0][j];
      pivot_col = j;
    }
  }
  printf("Most negative column in row[0] is col %d = %g.\n", pivot_col, lowest);
  if( lowest >= 0 ) {
    return -1; // All positive columns in row[0], this is optimal.
  }
  return pivot_col;
}

// Find the pivot_row, with smallest positive ratio = col[0] / col[pivot]
int find_pivot_row(Tableau *tab, int pivot_col) {
  int i, pivot_row = 0;
  double min_ratio = -1;
  printf("Ratios A[row_i,0]/A[row_i,%d] = [",pivot_col);
  for(i=1;i<tab->m;i++){
    double ratio = tab->mat[i][0] / tab->mat[i][pivot_col];
    printf("%3.2lf, ", ratio);
    if ( (ratio > 0  && ratio < min_ratio ) || min_ratio < 0 ) {
      min_ratio = ratio;
      pivot_row = i;
    }
  }
  printf("].\n");
  if (min_ratio == -1)
    return -1; // Unbounded.
  printf("Found pivot A[%d,%d], min positive ratio=%g in row=%d.\n",
      pivot_row, pivot_col, min_ratio, pivot_row);
  return pivot_row;
}

void add_slack_variables(Tableau *tab) {
  int i, j;
  for(i=1; i<tab->m; i++) {
    for(j=1; j<tab->m; j++)
      tab->mat[i][j + tab->n -1] = (i==j);
  }
  tab->n += tab->m -1;
}

void check_b_positive(Tableau *tab) {
  int i;
  for(i=1; i<tab->m; i++)
    assert(tab->mat[i][0] >= 0);
}

// Given a column of identity matrix, find the row containing 1.
// return -1, if the column as not from an identity matrix.
int find_basis_variable(Tableau *tab, int col) {
  int i, xi=-1;
  for(i=1; i < tab->m; i++) {
    if (equal( tab->mat[i][col],1) ) {
      if (xi == -1)
        xi=i;   // found first '1', save this row number.
      else
        return -1; // found second '1', not an identity matrix.

    } else if (!equal( tab->mat[i][col],0) ) {
      return -1; // not an identity matrix column.
    }
  }
  return xi;
}

void print_optimal_vector(Tableau *tab, char *message) {
  int j, xi;
  printf("%s at ", message);
  for(j=1;j<tab->n;j++) { // for each column.
    xi = find_basis_variable(tab, j);
    if (xi != -1)
      printf("x%d=%3.2lf, ", j, tab->mat[xi][0] );
    else
      printf("x%d=0, ", j);
  }
  printf("\n");
} 

void simplex(Tableau *tab) {
  int loop=0;
  add_slack_variables(tab);
  check_b_positive(tab);
  print_tableau(tab,"Padded with slack variables");
  while( ++loop ) {
    int pivot_col, pivot_row;

    pivot_col = find_pivot_column(tab);
    if( pivot_col < 0 ) {
      printf("Found optimal value=A[0,0]=%3.2lf (no negatives in row 0).\n",
        tab->mat[0][0]);
      print_optimal_vector(tab, "Optimal vector");
      break;
    }
    printf("Entering variable x%d to be made basic, so pivot_col=%d.\n",
      pivot_col, pivot_col);

    pivot_row = find_pivot_row(tab, pivot_col);
    if (pivot_row < 0) {
      printf("unbounded (no pivot_row).\n");
      break;
    }
    printf("Leaving variable x%d, so pivot_row=%d\n", pivot_row, pivot_row);

    pivot_on(tab, pivot_row, pivot_col);
    print_tableau(tab,"After pivoting");
    print_optimal_vector(tab, "Basic feasible solution");

    if(loop > 20) {
      printf("Too many iterations > %d.\n", loop);
      break;
    }
  }
}
void Print_EndResult(Tableau *tab)
{ 
  nl(70);
  printf("\n");
  int k=0;
for(int i=1;i<NOC;i++)
{
  printf("x%d:",i);

  if(strlen(UP[k])==0 )
    k++;
  
  printf("%s\n",UP[k]);
  k++;
  
}

}

int main(int argc, char *argv[])
{ 
  char ch;
  ShowStates();
    TableauInput();
   if (argc > 1) { // usage: cmd datafile
    read_tableau(&tab, argv[1]);
  }
  print_tableau(&tab,"Initial");
  simplex(&tab);
  Print_EndResult(&tab);
  printf("Press 1 to EXIT");
  while(1)
  {
  ch=getch();
  if(ch=='1')
  return 0;
  }
  
}