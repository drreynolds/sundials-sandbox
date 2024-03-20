/* -----------------------------------------------------------------
 * Programmer(s): Daniel Reynolds @ SMU
 * -----------------------------------------------------------------
 * SUNDIALS Copyright Start
 * Copyright (c) 2002-2024, Lawrence Livermore National Security
 * and Southern Methodist University.
 * All rights reserved.
 *
 * See the top-level LICENSE and NOTICE files for details.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * SUNDIALS Copyright End
 * -----------------------------------------------------------------
 * This is the header file for a custom SUNLinearSolver
 * implementation (note that this is just SUNDIALS' SPTFQMR solver).
 * -----------------------------------------------------------------*/

#ifndef _MY_SUNLINSOL_H
#define _MY_SUNLINSOL_H

#include <sundials/sundials_linearsolver.h>
#include <sundials/sundials_matrix.h>
#include <sundials/sundials_nvector.h>
#include <sundials/sundials_math.h>

#ifdef __cplusplus /* wrapper to enable C++ usage */
extern "C" {
#endif

/* Default solver parameters */
#define MY_MAXL_DEFAULT 5

/* ------------------------------------------
 * Custom Implementation of SUNLinearSolver
 * ------------------------------------------ */

struct _MySUNLinearSolverContent
{
  int maxl;
  int pretype;
  sunbooleantype zeroguess;
  int numiters;
  sunrealtype resnorm;
  int last_flag;

  SUNATimesFn ATimes;
  void* ATData;
  SUNPSetupFn Psetup;
  SUNPSolveFn Psolve;
  void* PData;

  N_Vector s1;
  N_Vector s2;
  N_Vector r_star;
  N_Vector q;
  N_Vector d;
  N_Vector v;
  N_Vector p;
  N_Vector* r;
  N_Vector u;
  N_Vector vtemp1;
  N_Vector vtemp2;
  N_Vector vtemp3;
};

typedef struct _MySUNLinearSolverContent* MySUNLinearSolverContent;

/* -------------------------------------
 * Exported Functions
 * -------------------------------------- */

SUNDIALS_EXPORT SUNLinearSolver SUNLinSol_Mine(N_Vector y, int pretype,
                                               int maxl, SUNContext sunctx);
SUNDIALS_EXPORT int SUNLinSolSetPrecType_Mine(SUNLinearSolver S,
                                              int pretype);
SUNDIALS_EXPORT int SUNLinSolSetMaxl_Mine(SUNLinearSolver S, int maxl);
SUNDIALS_EXPORT SUNLinearSolver_Type SUNLinSolGetType_Mine(SUNLinearSolver S);
SUNDIALS_EXPORT SUNLinearSolver_ID SUNLinSolGetID_Mine(SUNLinearSolver S);
SUNDIALS_EXPORT int SUNLinSolInitialize_Mine(SUNLinearSolver S);
SUNDIALS_EXPORT int SUNLinSolSetATimes_Mine(SUNLinearSolver S,
                                            void* A_data,
                                            SUNATimesFn ATimes);
SUNDIALS_EXPORT int SUNLinSolSetPreconditioner_Mine(SUNLinearSolver S,
                                                    void* P_data,
                                                    SUNPSetupFn Pset,
                                                    SUNPSolveFn Psol);
SUNDIALS_EXPORT int SUNLinSolSetScalingVectors_Mine(SUNLinearSolver S,
                                                    N_Vector s1,
                                                    N_Vector s2);
SUNDIALS_EXPORT int SUNLinSolSetZeroGuess_Mine(SUNLinearSolver S,
                                               sunbooleantype onoff);
SUNDIALS_EXPORT int SUNLinSolSetup_Mine(SUNLinearSolver S, SUNMatrix A);
SUNDIALS_EXPORT int SUNLinSolSolve_Mine(SUNLinearSolver S, SUNMatrix A,
                                        N_Vector x, N_Vector b,
                                        sunrealtype tol);
SUNDIALS_EXPORT int SUNLinSolNumIters_Mine(SUNLinearSolver S);
SUNDIALS_EXPORT sunrealtype SUNLinSolResNorm_Mine(SUNLinearSolver S);
SUNDIALS_EXPORT N_Vector SUNLinSolResid_Mine(SUNLinearSolver S);
SUNDIALS_EXPORT sunindextype SUNLinSolLastFlag_Mine(SUNLinearSolver S);
SUNDIALS_EXPORT int SUNLinSolSpace_Mine(SUNLinearSolver S,
                                        long int* lenrwLS,
                                        long int* leniwLS);
SUNDIALS_EXPORT int SUNLinSolFree_Mine(SUNLinearSolver S);

#ifdef __cplusplus
}
#endif

#endif

/*---- end of file ----*/
