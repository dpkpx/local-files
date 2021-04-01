//------------------------------------------------------------
// Prog. To Demo Random Data File Handling In Binary Mode.
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
  return;
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
  return;
}

//---Printing Record On Screen.
void PrintRecord(char *title, Student &s)
{
  system("cls");
  printf("\n%s:\n", title);
  int t = strlen(title);
  for (int p = 0; p < t; p++)
    printf("~");
  printf("\nRoll Number        : %d", s.roll);
  printf("\nStudent Name        : %s", s.name);
  for (int i = 0; i < 6; i++)
    printf("\nMarks In Subject-%d  : %03d", i + 1, s.sub[i]);
  printf("\n");
  printf("\nTotal Marks Obtained: %03d", s.tmo);
  printf("\nTotal Maximum Marks : %03d", s.tmm);
  printf("\nPercentage Scored   : %06.2f", s.per);
  printf("\nResult Declared     : %s", s.res);
  printf("\nDivision Scored     : %s", s.div);
  Pause("");
  return;
}

//---Add New Records.
void AddRecord(void)
{
  char yn1, yn2;
  Student s;
  FILE *fp = fopen("YYY.BIN", "a+b");
  do
  {
    system("cls");
    printf("\nADD NEW RECORD:");
    printf("\n~~~~~~~~~~~~~~~\n");
    printf("Enter Roll Numbeer      : ");
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
    yn1 = getche();
    if (toupper(yn1) == 'Y')
      fwrite(&s, sizeof(Student), 1, fp);
    printf("\n\nWant To Add More Records (Y=Yes): ");
    yn2 = getche();
  } while (toupper(yn2) == 'Y');
  fclose(fp);
  return;
}

//---View Any Record.
void ViewAnyRecord(void)
{
  int i, rec, trec;
  Student s;
  FILE *fp = fopen("YYY.BIN", "r+b");
  system("cls");
  printf("\nVIEW ANY RECORD:");
  printf("\n~~~~~~~~~~~~~~~~");
  if (fp == NULL)
  {
    Pause("\nFile Does Not Exist, Try Later.");
    return;
  }
  do
  {
    system("cls");
    printf("\nVIEW ANY RECORD:");
    printf("\n~~~~~~~~~~~~~~~~");
    fseek(fp, 0, SEEK_END);
    trec = ftell(fp) / sizeof(Student);
    printf("\nEnter Record No. Between 1-%d & 0 To Exit: ", trec);
    scanf("%d", &rec);
    if (rec >= 1 && rec <= trec)
    {
      fseek(fp, sizeof(Student) * (rec - 1), SEEK_SET);
      fread(&s, sizeof(Student), 1, fp);
      PrintRecord("VIEW ANY RECORD", s);
    }
    else if (rec == 0)
      break;
    else
      Pause("Please Enter Appropriate Record No.");
  } while (rec != 0);
  fclose(fp);
  return;
}

//---Search An Record.
void SearchRecord(void)
{
  int i, flag = 0, src;
  char yn;
  Student s;
  FILE *fp = fopen("YYY.BIN", "r+b");
  system("cls");
  printf("\nSEARCH AN RECORDS:");
  printf("\n~~~~~~~~~~~~~~~~~~");
  if (fp == NULL)
  {
    Pause("\nFile Does Not Exist, Try Later.");
    return;
  }
  do
  {
    system("cls");
    printf("\nSEARCH AN RECORDS:");
    printf("\n~~~~~~~~~~~~~~~~~~");
    printf("\nEnter Roll Number To Search: ");
    scanf("%d", &src);
    rewind(fp);
    while (!feof(fp))
    {
      fread(&s, sizeof(Student), 1, fp);
      if (s.roll == src)
      {
        PrintRecord("SEARCH AN RECORDS", s);
        flag = 1;
      }
    }
    if (flag != 1)
      Pause("Given Roll No. Does Not Exist. Try Again.");
    printf("\n\nWant To Search Another Record (Y=Yes): ");
    yn = getche();
  } while (toupper(yn) == 'Y');
  fclose(fp);
  return;
}

//---Edit An Record.
void EditRecord(void)
{
  int i, rec, total;
  char yn1, yn2;
  Student s, t;
  FILE *fp = fopen("YYY.BIN", "r+b");
  system("cls");
  printf("\nEDIT AN RECORDS:");
  printf("\n~~~~~~~~~~~~~~~~");
  if (fp == NULL)
  {
    Pause("\nFile Does Not Exist, Try Later.");
    return;
  }
  do
  {
    system("cls");
    printf("\nEDIT AN RECORDS:");
    printf("\n~~~~~~~~~~~~~~~~");
    printf("\nEnter Record Number To Edit: ");
    scanf("%d", &rec);
    fseek(fp, 0, SEEK_END);
    total = ftell(fp) / sizeof(Student);
    if (rec >= 1 && rec <= total)
    {
      fseek(fp, sizeof(Student) * (rec - 1), SEEK_SET);
      fread(&s, sizeof(Student), 1, fp);
      PrintRecord("EDIT AN RECORDS", s);
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
      printf("\n\nIs Data Correct (Y=Yes): ");
      yn1 = getche();
      if (toupper(yn1) == 'Y')
      {
        fseek(fp, sizeof(Student) * (rec - 1), SEEK_SET);
        fwrite(&t, sizeof(Student), 1, fp);
      }
    }
    else
      Pause("Given Record No. Does Not Exist. Try Later.");
    printf("\nWant To Edit More Record (Y=Yes): ");
    yn2 = getche();
  } while (toupper(yn2) == 'Y');
  fclose(fp);
  return;
}

//---Delete An Record.
void DeleteRecord(void)
{
  int i, rec, total;
  char yn1, yn2;
  Student s;
  FILE *fp = fopen("YYY.BIN", "r+b");
  system("cls");
  printf("\nDELETE AN RECORD:");
  printf("\n~~~~~~~~~~~~~~~~~");
  if (fp == NULL)
  {
    Pause("\nFile Does Not Exist, Try Later.");
    return;
  }
  do
  {
    fseek(fp, 0, SEEK_END);
    total = ftell(fp) / sizeof(Student);
    system("cls");
    printf("\nDELETE AN RECORD:");
    printf("\n~~~~~~~~~~~~~~~~~");
    printf("\nEnter Record Number To Delete Between 1 & %d: ", total);
    scanf("%d", &rec);
    if (rec >= 1 && rec <= total)
    {
      fseek(fp, sizeof(Student) * (rec - 1), SEEK_SET);
      fread(&s, sizeof(Student), 1, fp);
      PrintRecord("DELETE AN RECOORD", s);
      printf("\n\nAre You Sure To Delete (Y=Yes): ");
      yn1 = getche();
      if (toupper(yn1) == 'Y')
      {
        s.roll = 0;
        strcpy(s.name, "");
        for (i = 0; i < 6; i++)
          s.sub[i] = 0;
        s.tmo = s.tmm = 0;
        s.per = 0.0;
        strcpy(s.res, "");
        strcpy(s.div, "");
        fseek(fp, sizeof(Student) * (rec - 1), SEEK_SET);
        fwrite(&s, sizeof(Student), 1, fp);
      }
      else
        Pause("Given Record No. Does Not Exist. Try Later.");
    }
    else
      Pause("Please Enter Record No. Within Range.");
    printf("\nWant To Delete More Records (Y=Yes): ");
    yn2 = getche();
  } while (toupper(yn2) == 'Y');
  fclose(fp);
  return;
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
    remove("YYY.BIN");
    Pause("All Records Deleted Successfully.");
  }
  return;
}

//---Sort Records.
void HouseKeeping(void)
{
  int i, j, k, total = 0;
  Student *s, t;
  FILE *fp = fopen("YYY.BIN", "r+b");
  system("cls");
  printf("\nSORTING RECORDS:");
  printf("\n~~~~~~~~~~~~~~~~");
  if (fp == NULL)
  {
    Pause("\nFile Does Not Exist, Try Later.");
    return;
  }
  printf("\nPlease Wait, While Housekeeping.....");
  fseek(fp, 0, SEEK_END);
  total = ftell(fp) / sizeof(Student);
  fseek(fp, 0, SEEK_SET);
  fread(s, sizeof(Student), total, fp);

  for (i = 0; i < total - 1; i++)
  {
    for (j = i + 1; j < total; j++)
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
  fclose(fp);
  fp = fopen("YYY.BIN", "w+b");
  for (i = 0; i < total; i++)
    if (s[i].roll != 0)
      fwrite(&s[i], sizeof(Student), 1, fp);
  fclose(fp);
  Pause("HouseKeeping Done Successfully.");
  return;
}

//---Report Generation.
void ReportGen(void)
{
  int i, total = 0, line;
  Student *s;
  FILE *fp = fopen("YYY.BIN", "r+b");
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
  fseek(fp, 0, SEEK_END);
  total = ftell(fp) / sizeof(Student);
  fseek(fp, 0, SEEK_SET);
  fread(s, sizeof(Student), total, fp);
  fclose(fp);
  for (i = 0; i < total; i++)
  {
    printf("\n|%04d|%-15s|%03d|%03d|%03d|%03d|%03d|%03d| %03d| %03d| %06.2f| %-6s| %-5s|",
           s[i].roll, s[i].name, s[i].sub[0], s[i].sub[1], s[i].sub[2],
           s[i].sub[3], s[i].sub[4], s[i].sub[5], s[i].tmo, s[i].tmm,
           s[i].per, s[i].res, s[i].div);
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
  return;
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
    printf("\n| 2. View Any Records.   |");
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
      ViewAnyRecord();
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
  return 0;
}
//---End Of File.
