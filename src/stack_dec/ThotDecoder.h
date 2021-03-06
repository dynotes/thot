/*
thot package for statistical machine translation
Copyright (C) 2013 Daniel Ortiz-Mart\'inez
 
This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public License
as published by the Free Software Foundation; either version 3
of the License, or (at your option) any later version.
 
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.
 
You should have received a copy of the GNU Lesser General Public License
along with this program; If not, see <http://www.gnu.org/licenses/>.
*/
 
/********************************************************************/
/*                                                                  */
/* Module: ThotDecoder.h                                            */
/*                                                                  */
/* Prototype file: ThotDecoder.h                                    */
/*                                                                  */
/* Description: thot decoder class.                                 */
/*                                                                  */
/********************************************************************/

#ifndef _ThotDecoder_h
#define _ThotDecoder_h

//--------------- Include files --------------------------------------

#if HAVE_CONFIG_H
#  include <thot_config.h>
#endif /* HAVE_CONFIG_H */

#include "ThotDecoderCommonVars.h"
#include "ThotDecoderPerUserVars.h"
#include "ThotDecoderState.h"
#include "ThotDecoderUserPars.h"
#include <options.h>
#include <pthread.h>

#ifndef THOT_DISABLE_PREPROC_CODE
#include "XRCE_PrePosProcessor1.h" 
#include "XRCE_PrePosProcessor2.h" 
#include "XRCE_PrePosProcessor3.h" 
#include "XRCE_PrePosProcessor4.h" 
#include "EU_PrePosProcessor1.h" 
#include "EU_PrePosProcessor2.h"
#endif

//--------------- Constants ------------------------------------------

// Default parameter values
#define TDEC_W_DEFAULT          0.4
#define TDEC_A_DEFAULT         10
#define TDEC_E_DEFAULT          2
#define TDEC_HEUR_DEFAULT       LOCAL_TD_HEURISTIC
#define TDEC_NOMON_DEFAULT      0

#define NBEST_LIST_SIZE_FOR_LLWEIGHT_UPDATE 1000
#define MINIMUM_WORD_LENGTH_TO_EXPAND 1    // Define the minimum
                                           // length in characters that
                                           // is required to expand a
                                           // a word using the word
                                           // predictor
#define DRR_ALPHA               0.01
#define DRR_BETA                0.01

//--------------- Classes --------------------------------------------

//--------------- ThotDecoder class

class ThotDecoder
{
 public:

      // Constructor
  ThotDecoder();

      // User related functions
  bool user_id_new(int user_id);
  void release_user_data(int user_id);
  
      // Main functions
  void release(void);
  void config(void);

      // Functions to initialize the decoder
  int initUsingCfgFile(std::string cfgFile,
                       ThotDecoderUserPars& tdup,
                       int verbose);
  int initUserPars(int user_id,
                   const ThotDecoderUserPars& tdup,
                   int verbose);

      // Functions to load models
  bool load_tm(const char* tmFilesPrefix,
               int verbose=0);
  bool load_lm(const char* lmFileName,
               int verbose=0);
  bool load_ecm(const char* ecmFilesPrefix,
                int verbose=0);

      // Functions to train models
  void setOnlineTrainPars(OnlineTrainingPars onlineTrainingPars,
                          int verbose=0);
  bool onlineTrainSentPair(int user_id,
                           const char *srcSent,
                           const char *refSent,
                           int verbose=0);
  void updateLogLinearWeights(std::string refSent,
                              WordGraph* wgPtr,
                              int verbose=0);
  bool trainEcm(int user_id,
                const char *strx,
                const char *stry,
                int verbose=0);

      // Functions to translate sentences
  void translateSentence(int user_id,
                         const char *sentenceToTranslate,
                         std::string& result,
                         int verbose=0);
  bool translateSentencePrintWg(int user_id,
                                const char *sentenceToTranslate,
                                std::string& result,
                                const char* wgFilename,
                                int verbose=0);
  bool sentPairVerCov(int user_id,
                      const char *srcSent,
                      const char *refSent,
                      std::string& result,
                      int verbose=0);
  
      // CAT-related functions
  void startCat(int user_id,
                const char *sentenceToTranslate,
                std::string &catResult,
                int verbose=0);
  void addStrToPref(int user_id,
                    const char *strToAddToPref,
                    RejectedWordsSet& rejectedWords,
                    std::string &catResult,
                    int verbose=0);
  void setPref(int user_id,
               const char *prefStr,
               RejectedWordsSet& rejectedWords,
               std::string &catResult,
               int verbose=0);
  void resetPrefix(int user_id,
                   int verbose=0);
  bool use_caseconv(int user_id,
                    const char *caseConvFile,
                    int verbose=0);

      // Pre/Post-processing functions
  std::string preprocStr(int user_id,
                         std::string str);
  std::string postprocStr(int user_id,
                         std::string str);
  
      // Clear translator data structures
  void clearTrans(int verbose=0);

      // Function to print the models
  bool printModels(const char *printPrefix,
                   int verbose=0);

      // Destructor
  ~ThotDecoder();

 private:

      // Data members
  std::map<int,size_t> userIdToIdx;
  Vector<bool> idxDataReleased;
  ThotDecoderState tdState;
  ThotDecoderCommonVars tdCommonVars;
  Vector<ThotDecoderPerUserVars> tdPerUserVarsVec;
  Vector<std::string> totalPrefixVec;

      // Mutexes and conditions
  pthread_mutex_t user_id_to_idx_mut;
  pthread_mutex_t atomic_op_mut;
  pthread_mutex_t non_atomic_op_mut;
  pthread_mutex_t preproc_mut;
  pthread_cond_t non_atomic_op_cond;
  unsigned int non_atomic_ops_running;

      // Mutex- and condition-related functions
  void wait_on_non_atomic_op_cond(void);
  void unlock_non_atomic_op_mut(void);  
  void increase_non_atomic_ops_running(void);
  void decrease_non_atomic_ops_running(void);

      // Functions to set decoder parameters
  void setNonMonotonicity(int nomon,
                          int verbose=0);
  void set_W(float _W,
             int verbose=0);
  void set_S(int user_id,
             unsigned int _S,
             int verbose=0);
  void set_A(unsigned int _A,
             int verbose=0);
  void set_E(unsigned int _E,
             int verbose=0);
  void set_be(int user_id,
              int _be,
              int verbose=0);
  bool set_G(int user_id,
             unsigned int _G,
             int verbose=0);
  void set_h(unsigned int _h,
             int verbose=0);
  bool set_np(int user_id,
              unsigned int _np,
              int verbose=0);
  bool set_wgp(int user_id,
               float _wgp,
               int verbose=0);
  void set_preproc(int user_id,
                   unsigned int _preprocId,
                   int verbose=0);
  void set_tmw(Vector<float> _tmwVec,
               int verbose=0);
  void set_ecw(Vector<float> _ecwVec,
               int verbose=0);
  void set_catw(int user_id,
                Vector<float> _catwVec,
                int verbose=0);
  bool set_wgh(const char *wgHandlerFileName,
               int verbose=0);

      // Functions to initialize variables for each user
  size_t get_vecidx_for_user_id(int user_id);
  int init_idx_data(size_t idx);
  void release_idx_data(size_t idx);

      // Auxiliary functions for translation
  std::string translateSentenceAux(size_t idx,
                                   std::string sentenceToTranslate,
                                   int verbose=0);

      // Pre-posprocessing related functions
  std::string robustObtainFinalOutput(BasePrePosProcessor* prePosProcessorPtr,
                                      std::string unpreprocPref,
                                      std::string preprocPrefUnexpanded,
                                      std::string preprocPref,
                                      std::string trans,
                                      bool caseconv);
  std::string postprocWithCriticalError(BasePrePosProcessor* prePosProcessorPtr,
                                        std::string unpreprocPref,
                                        std::string preprocPrefUnexpanded,
                                        std::string preprocPref,
                                        std::string trans,
                                        bool caseconv);
  std::string robustMergeTransWithUserPref(std::string trans,
                                           std::string totalPrefix);
  std::string robustMergePostProcTransWithUserPref(std::string postproctrans,
                                                   std::string totalPrefix);
  std::string expandLastWord(std::string& partialSent);
  std::string getWordCompletion(std::string uncompleteWord,
                                std::string completeWord);

};
#endif
