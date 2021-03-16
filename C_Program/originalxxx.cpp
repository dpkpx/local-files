//------------------------------------------------------------
// Prog. To Demo Sequentail Data File Handling In Text Mode.
//------------------------------------------------------------

//---Required List Of Header Files.
#include <conio.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
int gotoxy(int x, int y)
{
  COORD coord = {x, y};
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//---Structure Of Record.
struct Student
{
  int roll;
  char name[35];
  int sub[6];
  int tmo;
  int tmm;
  float per;
  char res[8];
  char div[8];
};

//---Prints The Given Message On Screen.
void Pause(char *msg)
{
  printf("\n\nMESSAGE: %s", msg);
  printf("\nPress Any Key To Continue...");
  fflush(stdin);
  getch();
}

//---To Compute Result.
void Compute(Student &s)
{
  s.tmo = 0;
  s.tmm = 600;
  for (int i = 0; i < 6; i++)
    s.tmo += s.sub[i];
  s.per = (float)s.tmo / 6.0;
  if (s.per >= 0.0 && s.per < 35.0)
  {
    strcpy(s.res, "FAILED");
    strcpy(s.div, "NIL");
  }
  else if (s.per >= 35.0 && s.per < 45.0)
  {
    strcpy(s.res, "PASSED");
    strcpy(s.div, "III");
  }
  else if (s.per >= 45.0 && s.per < 60.0)
  {
    strcpy(s.res, "PASSED");
    strcpy(s.div, "II");
  }
  else if (s.per >= 60.0 && s.per < 75.0)
  {
    strcpy(s.res, "PASSED");
    strcpy(s.div, "I");
  }
  else if (s.per >= 75.0 && s.per <= 100.0)
  {
    strcpy(s.res, "PASSED");
    strcpy(s.div, "BEST");
  }
  else
  {
    strcpy(s.res, "X");
    strcpy(s.div, "X");
  }
}

//---Add New Records.
void AddRecord(void)
{
  char yn;
  Student s;
  system("cls");
  printf("\nADD NEW RECORD:");
  printf("\n~~~~~~~~~~~~~~~\n");
  printf("Enter Roll Number      : ");
  scanf("%d", &s.roll);
  printf("Enter Student Name      : ");
  scanf("%s", s.name);
  for (int i = 0; i < 6; i++)
  {
    printf("Enter Marks Of Subject-%d: ", i + 1);
    scanf("%d", &s.sub[i]);
  }
  Compute(s);
  printf("\nTotal Marks Obtained    : %03d", s.tmo);
  printf("\nTotal Maximum Marks     : %03d", s.tmm);
  printf("\nPercentage Scored       : %06.2f", s.per);
  printf("\nResult Declared         : %s", s.res);
  printf("\nDivision Scored         : %s", s.div);
  printf("\n\nIs Data Correct (Y=Yes): ");
  yn = getche();
  if (toupper(yn) == 'Y')
  {
    FILE *fp = fopen("XXX.TXT", "at+");
    fprintf(fp, "%d %s %03d %03d %03d %03d %03d %03d %03d %03d %06.2f %s %s\n",
            s.roll, s.name,
            s.sub[0], s.sub[1], s.sub[2], s.sub[3], s.sub[4], s.sub[5],
            s.tmo, s.tmm, s.per, s.res, s.div);
    fclose(fp);
  }
}

//---View All Records.
void ViewAllRecords(void)
{
  int i;
  Student s;
  FILE *fp = fopen("XXX.TXT", "rt+");
  system("cls");
  printf("\nVIEW ALL RECORDS:");
  printf("\n~~~~~~~~~~~~~~~~~");
  if (fp == NULL)
  {
    Pause("\nFile Does Not Exist, Try Later.");
    return;
  }
  while (!feof(fp))
  {
    fscanf(fp, "%d %s %d %d %d %d %d %d %d %d %f %s %s",
           &s.roll, s.name,
           &s.sub[0], &s.sub[1], &s.sub[2], &s.sub[3], &s.sub[4], &s.sub[5],
           &s.tmo, &s.tmm, &s.per, s.res, s.div);
    if (feof(fp))
      break;
    system("cls");
    printf("\nVIEW ALL RECORDS:");
    printf("\n~~~~~~~~~~~~~~~~~");
    printf("\nRoll Number        : %d", s.roll);
    printf("\nStudent Name        : %s", s.name);
    for (i = 0; i < 6; i++)
      printf("\nMarks In Subject-%d  : %03d", i + 1, s.sub[i]);
    printf("\n");
    printf("\nTotal Marks Obtained: %03d", s.tmo);
    printf("\nTotal Maximum Marks : %03d", s.tmm);
    printf("\nPercentage Scored   : %06.2f", s.per);
    printf("\nResult Declared     : %s", s.res);
    printf("\nDivision Scored     : %s", s.div);
    Pause("");
  }
  fclose(fp);
}

//---Search An Record.
void SearchRecord(void)
{
  int i, flag = 0, src;
  Student s;
  FILE *fp = fopen("XXX.TXT", "rt+");
  system("cls");
  printf("\nSEARCH AN RECORDS:");
  printf("\n~~~~~~~~~~~~~~~~~~");
  if (fp == NULL)
  {
    Pause("\nFile Does Not Exist, Try Later.");
    return;
  }
  system("cls");
  printf("\nSEARCH AN RECORDS:");
  printf("\n~~~~~~~~~~~~~~~~~~");
  printf("\nEnter Roll Number To Search: ");
  scanf("%d", &src);
  while (!feof(fp))
  {
    fscanf(fp, "%d %s %d %d %d %d %d %d %d %d %f %s %s",
           &s.roll, s.name,
           &s.sub[0], &s.sub[1], &s.sub[2], &s.sub[3], &s.sub[4], &s.sub[5],
           &s.tmo, &s.tmm, &s.per, s.res, s.div);
    if (feof(fp))
      break;
    if (s.roll == src)
    {
      system("cls");
      printf("\nSEARCH AN RECORDS:");
      printf("\n~~~~~~~~~~~~~~~~~~");
      printf("\nRoll Number        : %d", s.roll);
      printf("\nStudent Name        : %s", s.name);
      for (i = 0; i < 6; i++)
        printf("\nMarks In Subject-%d  : %03d", i + 1, s.sub[i]);
      printf("\n");
      printf("\nTotal Marks Obtained: %03d", s.tmo);
      printf("\nTotal Maximum Marks : %03d", s.tmm);
      printf("\nPercentage Scored   : %06.2f", s.per);
      printf("\nResult Declared     : %s", s.res);
      printf("\nDivision Scored     : %s", s.div);
      Pause("");
      flag = 1;
    }
  }
  if (flag != 1)
    Pause("Given Roll No. Does Not Exist. Try Again.");
  fclose(fp);
}

//---Edit An Record.
void EditRecord(void)
{
  int i, flag = 0, src;
  char yn;
  Student s, t;
  FILE *fp1 = fopen("XXX.TXT", "rt+");
  system("cls");
  printf("\nEDIT AN RECORDS:");
  printf("\n~~~~~~~~~~~~~~~~");
  if (fp1 == NULL)
  {
    Pause("\nFile Does Not Exist, Try Later.");
    return;
  }
  FILE *fp2 = fopen("TMP.TXT", "at+");
  system("cls");
  printf("\nEDIT AN RECORDS:");
  printf("\n~~~~~~~~~~~~~~~~");
  printf("\nEnter Roll Number To Edit: ");
  scanf("%d", &src);
  while (!feof(fp1))
  {
    fscanf(fp1, "%d %s %d %d %d %d %d %d %d %d %f %s %s",
           &s.roll, s.name,
           &s.sub[0], &s.sub[1], &s.sub[2], &s.sub[3], &s.sub[4], &s.sub[5],
           &s.tmo, &s.tmm, &s.per, s.res, s.div);
    if (feof(fp1))
      break;
    if (s.roll == src)
    {
      flag = 1;
      system("cls");
      printf("\nEDIT AN RECORDS:");
      printf("\n~~~~~~~~~~~~~~~~");
      printf("\nRoll Number        : %d", s.roll);
      printf("\nStudent Name        : %s", s.name);
      for (i = 0; i < 6; i++)
        printf("\nMarks In Subject-%d  : %03d", i + 1, s.sub[i]);
      printf("\n");
      printf("\nTotal Marks Obtained: %03d", s.tmo);
      printf("\nTotal Maximum Marks : %03d", s.tmm);
      printf("\nPercentage Scored   : %06.2f", s.per);
      printf("\nResult Declared     : %s", s.res);
      printf("\nDivision Scored     : %s", s.div);
      gotoxy(40, 4);
      scanf("%d", &t.roll);
      gotoxy(40, 5);
      scanf("%s", t.name);
      for (i = 0; i < 6; i++)
      {
        gotoxy(40, i + 6);
        scanf("%d", &t.sub[i]);
      }
      Compute(t);
      gotoxy(40, 13);
      printf("%03d", t.tmo);
      gotoxy(40, 14);
      printf("%03d", t.tmm);
      gotoxy(40, 15);
      printf("%06.2f", t.per);
      gotoxy(40, 16);
      printf("%s", t.res);
      gotoxy(40, 17);
      printf("%s", t.div);
      printf("\n\nIs Data Correct(Y=Yes); ");
      yn = getche();
      if (toupper(yn) == 'Y')
        fprintf(fp2, "%d %s %03d %03d %03d %03d %03d %03d %03d %03d %06.2f %s %s\n",
                t.roll, t.name,
                t.sub[0], t.sub[1], t.sub[2], t.sub[3], t.sub[4], t.sub[5],
                t.tmo, t.tmm, t.per, t.res, t.div);
      else
        fprintf(fp2, "%d %s %03d %03d %03d %03d %03d %03d %03d %03d %06.2f %s %s\n",
                s.roll, s.name,
                s.sub[0], s.sub[1], s.sub[2], s.sub[3], s.sub[4], s.sub[5],
                s.tmo, s.tmm, s.per, s.res, s.div);
    }
    else
      fprintf(fp2, "%d %s %03d %03d %03d %03d %03d %03d %03d %03d %06.2f %s %s\n",
              s.roll, s.name,
              s.sub[0], s.sub[1], s.sub[2], s.sub[3], s.sub[4], s.sub[5],
              s.tmo, s.tmm, s.per, s.res, s.div);
  }
  if (flag != 1)
    Pause("Given Roll No. Does Not Exist. Try Again.");
  fclose(fp1);
  fclose(fp2);
  remove("XXX.TXT");
  rename("TMP.TXT", "XXX.TXT");
}

//---Delete An Record.
void DeleteRecord(void)
{
  int i, flag = 0, src;
  char yn;
  Student s;
  FILE *fp1 = fopen("XXX.TXT", "rt+");
  system("cls");
  printf("\nDELETE AN RECORD:");
  printf("\n~~~~~~~~~~~~~~~~~");
  if (fp1 == NULL)
  {
    Pause("\nFile Does Not Exist, Try Later.");
    return;
  }
  FILE *fp2 = fopen("TMP.TXT", "at+");
  system("cls");
  printf("\nDELETE AN RECORD:");
  printf("\n~~~~~~~~~~~~~~~~~");
  printf("\nEnter Roll Number To Delete: ");
  scanf("%d", &src);
  while (!feof(fp1))
  {
    fscanf(fp1, "%d %s %d %d %d %d %d %d %d %d %f %s %s",
           &s.roll, s.name,
           &s.sub[0], &s.sub[1], &s.sub[2], &s.sub[3], &s.sub[4], &s.sub[5],
           &s.tmo, &s.tmm, &s.per, s.res, s.div);
    if (feof(fp1))
      break;
    if (s.roll == src)
    {
      flag = 1;
      system("cls");
      printf("\nDELETE AN RECORD:");
      printf("\n~~~~~~~~~~~~~~~~~");
      printf("\nRoll Number        : %d", s.roll);
      printf("\nStudent Name        : %s", s.name);
      for (i = 0; i < 6; i++)
        printf("\nMarks In Subject-%d  : %03d", i + 1, s.sub[i]);
      printf("\n");
      printf("\nTotal Marks Obtained: %03d", s.tmo);
      printf("\nTotal Maximum Marks : %03d", s.tmm);
      printf("\nPercentage Scored   : %06.2f", s.per);
      printf("\nResult Declared     : %s", s.res);
      printf("\nDivision Scored     : %s", s.div);
      printf("\n\nAre You Sure(Y=Yes); ");
      yn = getche();
      if (toupper(yn) != 'Y')
        fprintf(fp2, "%d %s %03d %03d %03d %03d %03d %03d %03d %03d %06.2f %s %s\n",
                s.roll, s.name,
                s.sub[0], s.sub[1], s.sub[2], s.sub[3], s.sub[4], s.sub[5],
                s.tmo, s.tmm, s.per, s.res, s.div);
    }
    else
      fprintf(fp2, "%d %s %03d %03d %03d %03d %03d %03d %03d %03d %06.2f %s %s\n",
              s.roll, s.name,
              s.sub[0], s.sub[1], s.sub[2], s.sub[3], s.sub[4], s.sub[5],
              s.tmo, s.tmm, s.per, s.res, s.div);
  }
  if (flag != 1)
    Pause("Given Roll No. Does Not Exist. Try Again.");
  fclose(fp1);
  fclose(fp2);
  remove("XXX.TXT");
  rename("TMP.TXT", "XXX.TXT");
}

//---Delete All Records.
void DeleteAll(void)
{
  char yn;
  system("cls");
  printf("\nDELETE ALL RECORDS:");
  printf("\n~~~~~~~~~~~~~~~~~~~");
  printf("\nAre You Sure To Delete All Records(Y=Yes): ");
  yn = getche();
  if (toupper(yn) == 'Y')
  {
    remove("XXX.TXT");
    Pause("All Records Deleted Successfully.");
  }
}

//---Sort Records.
void HouseKeeping(void)
{
  int i, j, k, n = 0;
  Student s[99], t;
  FILE *fp1 = fopen("XXX.TXT", "rt+");
  system("cls");
  printf("\nSORTING RECORDS:");
  printf("\n~~~~~~~~~~~~~~~~");
  if (fp1 == NULL)
  {
    Pause("\nFile Does Not Exist, Try Later.");
    return;
  }
  printf("\nPlease Wait, While Housekeeping.....");
  while (!feof(fp1))
  {
    fscanf(fp1, "%d %s %d %d %d %d %d %d %d %d %f %s %s",
           &s[n].roll, s[n].name,
           &s[n].sub[0], &s[n].sub[1], &s[n].sub[2], &s[n].sub[3], &s[n].sub[4], &s[n].sub[5],
           &s[n].tmo, &s[n].tmm, &s[n].per, s[n].res, s[n].div);
    if (feof(fp1))
      break;
    n++;
  }
  fclose(fp1);
  for (i = 0; i < n - 1; i++)
  {
    for (j = i + 1; j < n; j++)
    {
      if (s[i].roll > s[j].roll)
      {
        t.roll = s[i].roll;
        strcpy(t.name, s[i].name);
        for (k = 0; k < 6; k++)
          t.sub[k] = s[i].sub[k];
        t.tmo = s[i].tmo;
        t.tmm = s[i].tmm;
        t.per = s[i].per;
        strcpy(t.res, s[i].res);
        strcpy(t.div, s[i].div);

        s[i].roll = s[j].roll;
        strcpy(s[i].name, s[j].name);
        for (k = 0; k < 6; k++)
          s[i].sub[k] = s[j].sub[k];
        s[i].tmo = s[j].tmo;
        s[i].tmm = s[j].tmm;
        s[i].per = s[j].per;
        strcpy(s[i].res, s[j].res);
        strcpy(s[i].div, s[j].div);

        s[j].roll = t.roll;
        strcpy(s[j].name, t.name);
        for (k = 0; k < 6; k++)
          s[j].sub[k] = t.sub[k];
        s[j].tmo = t.tmo;
        s[j].tmm = t.tmm;
        s[j].per = t.per;
        strcpy(s[j].res, t.res);
        strcpy(s[j].div, t.div);
      }
    }
  }
  FILE *fp2 = fopen("TMP.TXT", "wt+");
  for (i = 0; i < n; i++)
    fprintf(fp2, "%d %s %03d %03d %03d %03d %03d %03d %03d %03d %06.2f %s %s\n",
            s[i].roll, s[i].name,
            s[i].sub[0], s[i].sub[1], s[i].sub[2], s[i].sub[3], s[i].sub[4], s[i].sub[5],
            s[i].tmo, s[i].tmm, s[i].per, s[i].res, s[i].div);
  fclose(fp2);
  remove("XXX.TXT");
  rename("TMP.TXT", "XXX.TXT");
  Pause("HouseKeeping Done Successfully.");
}

//---Report Generation.
void ReportGen(void)
{
  int line;
  Student s;
  FILE *fp = fopen("XXX.TXT", "rt+");
  system("cls");
  printf("\nREPORT GENERATION:");
  printf("\n~~~~~~~~~~~~~~~~~~");
  if (fp == NULL)
  {
    Pause("\nFile Does Not Exist, Try Later.");
    return;
  }
  system("cls");
  gotoxy(22, 1);
  printf("PNADU & DATERIA INTERNATIONAL SCHOOL");
  gotoxy(28, 2);
  printf("Students Report Details");
  printf("\n/-----------------------------------------------------------------------------\\");
  printf("\n|Roll| Students Name |S-1|S-2|S-3|S-4|S-5|S-6| TMO| TMM|Percent| Result| Div. |");
  printf("\n|----|---------------|---|---|---|---|---|---|----|----|-------|-------|------|");
  line = 6;
  while (!feof(fp))
  {
    fscanf(fp, "%d %s %d %d %d %d %d %d %d %d %f %s %s",
           &s.roll, s.name,
           &s.sub[0], &s.sub[1], &s.sub[2], &s.sub[3], &s.sub[4], &s.sub[5],
           &s.tmo, &s.tmm, &s.per, s.res, s.div);
    if (feof(fp))
      break;
    printf("\n|%04d|%-15s|%03d|%03d|%03d|%03d|%03d|%03d| %03d| %03d| %06.2f| %-6s| %-5s|",
           s.roll, s.name, s.sub[0], s.sub[1], s.sub[2], s.sub[3], s.sub[4], s.sub[5],
           s.tmo, s.tmm, s.per, s.res, s.div);
    line++;
    if (line >= 22)
    {
      printf("\n\\-----------------------------------------------------------------------------/");
      Pause("---NEXT PAGE---");
      system("cls");
      gotoxy(22, 1);
      printf("PNADU & DATERIA INTERNATIONAL SCHOOL");
      gotoxy(28, 2);
      printf("Students Report Details");
      printf("\n/-----------------------------------------------------------------------------\\");
      printf("\n|Roll| Students Name |S-1|S-2|S-3|S-4|S-5|S-6| TMO| TMM|Percent| Result| Div. |");
      printf("\n|----|---------------|---|---|---|---|---|---|----|----|-------|-------|------|");
      line = 6;
    }
  }
  printf("\n\\-----------------------------------------------------------------------------/");
  Pause("---END OF REPORT---");
  fclose(fp);
}

//---Main Program Body.
int main(void)
{
  char choice;
  do
  {
    system("cls");
    printf("\n/------------------------\\");
    printf("\n|   M A I N    M E N U   |");
    printf("\n|------------------------|");
    printf("\n| 1. Add New Record.     |");
    printf("\n| 2. View All Records.   |");
    printf("\n| 3. Search An Record.   |");
    printf("\n| 4. Edit An Record.     |");
    printf("\n| 5. Delete An Record.   |");
    printf("\n| 6. Delete All Records. |");
    printf("\n| 7. Sort All Records.   |");
    printf("\n| 8. Generate Report.    |");
    printf("\n| 9. May I Help You.     |");
    printf("\n| 0. Exit / Quit.        |");
    printf("\n|------------------------|");
    printf("\n| Enter Choice (0-9):    |");
    printf("\n\\------------------------/");
    gotoxy(23, 15);
    fflush(stdin);
    choice = getche();
    switch (choice)
    {
    case '1':
      AddRecord();
      break;
    case '2':
      ViewAllRecords();
      break;
    case '3':
      SearchRecord();
      break;
    case '4':
      EditRecord();
      break;
    case '5':
      DeleteRecord();
      break;
    case '6':
      DeleteAll();
      break;
    case '7':
      HouseKeeping();
      break;
    case '8':
      ReportGen();
      break;
    case '9':
      Pause("Pandu Has Not Defined Any Help For You.");
      break;
    case '0':
      Pause("T A T A ,   B Y E - B Y E");
      break;
    default:
      Pause("Inavlid Choice, You May Select Between 0 & 9 Only.");
    }
  } while (choice != '0');
  system("cls");
  return 0;
}
//---End Of File.
