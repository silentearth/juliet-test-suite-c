/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE126_Buffer_Overread__CWE129_fscanf_45.c
Label Definition File: CWE126_Buffer_Overread__CWE129.label.xml
Template File: sources-sinks-45.tmpl.c
*/
/*
 * @description
 * CWE: 126 Buffer Overread
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Larger than zero but less than 10
 * Sinks:
 *    GoodSink: Ensure the array index is valid
 *    BadSink : Improperly check the array index by not checking the upper bound
 * Flow Variant: 45 Data flow: data passed as a static global variable from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

static int CWE126_Buffer_Overread__CWE129_fscanf_45_badData;
static int CWE126_Buffer_Overread__CWE129_fscanf_45_goodG2BData;
static int CWE126_Buffer_Overread__CWE129_fscanf_45_goodB2GData;

#ifndef OMITBAD

static void badSink()
{
    int data = CWE126_Buffer_Overread__CWE129_fscanf_45_badData;
    {
        int buffer[10] = { 0 };
        /* POTENTIAL FLAW: Attempt to access an index of the array that is above the upper bound
         * This check does not check the upper bounds of the array index */
        if (data >= 0)
        {
            printIntLine(buffer[data]);
        }
        else
        {
            printLine("ERROR: Array index is negative");
        }
    }
}

void CWE126_Buffer_Overread__CWE129_fscanf_45_bad()
{
    int data;
    /* Initialize data */
    data = -1;
    /* POTENTIAL FLAW: Read data from the console using fscanf() */
    fscanf(stdin, "%d", &data);
    CWE126_Buffer_Overread__CWE129_fscanf_45_badData = data;
    badSink();
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2BSink()
{
    int data = CWE126_Buffer_Overread__CWE129_fscanf_45_goodG2BData;
    {
        int buffer[10] = { 0 };
        /* POTENTIAL FLAW: Attempt to access an index of the array that is above the upper bound
         * This check does not check the upper bounds of the array index */
        if (data >= 0)
        {
            printIntLine(buffer[data]);
        }
        else
        {
            printLine("ERROR: Array index is negative");
        }
    }
}

static void goodG2B()
{
    int data;
    /* Initialize data */
    data = -1;
    /* FIX: Use a value greater than 0, but less than 10 to avoid attempting to
     * access an index of the array in the sink that is out-of-bounds */
    data = 7;
    CWE126_Buffer_Overread__CWE129_fscanf_45_goodG2BData = data;
    goodG2BSink();
}

/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2GSink()
{
    int data = CWE126_Buffer_Overread__CWE129_fscanf_45_goodB2GData;
    {
        int buffer[10] = { 0 };
        /* FIX: Properly validate the array index and prevent a buffer overread */
        if (data >= 0 && data < (10))
        {
            printIntLine(buffer[data]);
        }
        else
        {
            printLine("ERROR: Array index is out-of-bounds");
        }
    }
}

static void goodB2G()
{
    int data;
    /* Initialize data */
    data = -1;
    /* POTENTIAL FLAW: Read data from the console using fscanf() */
    fscanf(stdin, "%d", &data);
    CWE126_Buffer_Overread__CWE129_fscanf_45_goodB2GData = data;
    goodB2GSink();
}

void CWE126_Buffer_Overread__CWE129_fscanf_45_good()
{
    goodG2B();
    goodB2G();
}

#endif /* OMITGOOD */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */
#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE126_Buffer_Overread__CWE129_fscanf_45_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE126_Buffer_Overread__CWE129_fscanf_45_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif