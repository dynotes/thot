# general settings

LGMP=@LGMP@
ZLIB=@ZLIB@

AUTOMAKE_OPTIONS = subdir-objects

SUBDIRS= nlp_common incr_models sw_models phrase_models smt_preproc	\
error_correction downhill_simplex stack_dec

if CASMACAT_LIB_ENABLED
bin_PROGRAMS = thot_ilm_perp thot_calc_swm_lgprob thot_gen_sw_model	\
thot_sort_bin_ilextable thot_sort_bin_ihmmatable			\
thot_sort_bin_iibm2atable thot_merge_bin_ilextable			\
thot_merge_bin_ihmmatable thot_merge_bin_iibm2atable			\
thot_gen_bin_lex_filter_info thot_filter_bin_ilextable			\
thot_prune_bin_ilextable thot_alig_op thot_gen_phr_model thot_wg_proc	\
thot_dhs_step_by_step_min thot_dec_ms thot_aligner thot_dec_client	\
thot_dec_server thot_calc_bleu

else
bin_PROGRAMS = thot_ilm_perp thot_calc_swm_lgprob thot_gen_sw_model	\
thot_sort_bin_ilextable thot_sort_bin_ihmmatable			\
thot_sort_bin_iibm2atable thot_merge_bin_ilextable			\
thot_merge_bin_ihmmatable thot_merge_bin_iibm2atable			\
thot_gen_bin_lex_filter_info thot_filter_bin_ilextable			\
thot_prune_bin_ilextable thot_alig_op thot_gen_phr_model thot_wg_proc	\
thot_dhs_step_by_step_min thot_dec_ms thot_aligner thot_dec_client	\
thot_dec_server thot_calc_bleu
endif

if CASMACAT_LIB_ENABLED
lib_LTLIBRARIES = libthot.la libthot_casmacat.la
else
lib_LTLIBRARIES = libthot.la
endif

# flags
AM_CXXFLAGS= -W -Wno-deprecated -I$(srcdir)/nlp_common			\
-I$(srcdir)/incr_models -I$(srcdir)/sw_models -I$(srcdir)/phrase_models	\
-I$(srcdir)/smt_preproc -I$(srcdir)/error_correction			\
-I$(srcdir)/downhill_simplex -I$(srcdir)/stack_dec			\
-I$(CASMACAT_SERVER_LIB_HOME)/src/include

AM_CFLAGS= $(AM_CXXFLAGS)

LDADD = $(LGMP) $(ZLIB)

# sources
common_src_h= thot_config.h

nlp_common_h= nlp_common/WordIndex.h nlp_common/WordAligMatrix.h	\
nlp_common/uiPairHashF.h nlp_common/uiHashF.h nlp_common/TrieVecs.h	\
nlp_common/TrieOfWords.h nlp_common/Trie.h nlp_common/TrieBidOfWords.h	\
nlp_common/TrieBid.h nlp_common/StrProcUtils.h				\
nlp_common/StatModelDefs.h nlp_common/SingleWordVocab.h			\
nlp_common/SimpleTrie.h nlp_common/_simpleTrie.h nlp_common/Score.h	\
nlp_common/Prob.h nlp_common/printAligFuncs.h				\
nlp_common/PositionIndex.h nlp_common/OrderedVector.h			\
nlp_common/options.h nlp_common/NbestTransTable.h			\
nlp_common/NbestTableNode.h nlp_common/myVector.h			\
nlp_common/mem_alloc_utils.h nlp_common/MathFuncs.h			\
nlp_common/MathDefs.h nlp_common/lt_op_vec.h nlp_common/LogCount.h	\
nlp_common/LM_Defs.h nlp_common/ins_op_pair.h nlp_common/getline.h	\
nlp_common/getdelim.h nlp_common/ErrorDefs.h nlp_common/ctimer.h	\
nlp_common/Count.h nlp_common/ClassDic.h nlp_common/Bitset.h		\
nlp_common/BasicSocketUtils.h nlp_common/BaseNgramLM.h			\
nlp_common/BaseIncrNgramLM.h nlp_common/BackoffNode.h			\
nlp_common/awkInputStream.h
nlp_common_defs= nlp_common/WordAligMatrix.cc				\
nlp_common/StrProcUtils.cc nlp_common/SingleWordVocab.cc		\
nlp_common/Prob.cc nlp_common/printAligFuncs.cc nlp_common/options.cc	\
nlp_common/mem_alloc_utils.cc nlp_common/MathFuncs.cc			\
nlp_common/getline.c nlp_common/getdelim.c nlp_common/ctimer.c		\
nlp_common/ClassDic.cc nlp_common/BasicSocketUtils.cc			\
nlp_common/awkInputStream.cc

incr_models_h= incr_models/vecx_x_incr_enc.h				\
incr_models/vecx_x_incr_ecpm.h incr_models/vecx_x_incr_cptable.h	\
incr_models/lm_ienc.h incr_models/IncrNgramLM.h				\
incr_models/_incrNgramLM.h incr_models/IncrInterpONgramLM.h		\
incr_models/_incrInterpONgramLM.h incr_models/IncrEncoder.h		\
incr_models/_incrEncCondProbModel.h incr_models/IncrCondProbTable.h	\
incr_models/im_pair.h incr_models/BaseIncrEncoder.h			\
incr_models/BaseIncrEncCondProbModel.h					\
incr_models/BaseIncrCondProbTable.h incr_models/BaseIncrCondProbModel.h
incr_models_defs= incr_models/lm_ienc.cc incr_models/IncrNgramLM.cc	\
incr_models/IncrInterpONgramLM.cc

sw_models_h= sw_models/WeightedIncrNormSlm.h				\
sw_models/SwModelsSwModelTypes.h sw_models/SwModelsSlmTypes.h		\
sw_models/SwModelsShTypes.h sw_models/SwDefs.h sw_models/_swAligModel.h	\
sw_models/SmoothedIncrIbm1AligModel.h sw_models/SentPairCont.h		\
sw_models/_sentLengthModel.h sw_models/SentenceHandler.h		\
sw_models/LightSentenceHandler.h sw_models/LexAuxVar.h			\
sw_models/_incrSwAligModel.h sw_models/IncrLexTable.h			\
sw_models/IncrIbm1AligModel.h sw_models/IncrHmmP0AligModel.h		\
sw_models/IncrHmmAligTable.h sw_models/IncrHmmAligModel.h		\
sw_models/HmmAligInfo.h sw_models/DoubleMatrix.h			\
sw_models/BestLgProbForTrgWord.h sw_models/BaseSwAligModel.h		\
sw_models/BaseStepwiseAligModel.h sw_models/BaseSentLengthModel.h	\
sw_models/BaseSentenceHandler.h sw_models/aSourceHmm.h			\
sw_models/aSource.h sw_models/ashPidxPairHashF.h			\
sw_models/anjm1ip_anjiMatrix.h sw_models/anjiMatrix.h
sw_models_defs= sw_models/WeightedIncrNormSlm.cc			\
sw_models/SmoothedIncrIbm1AligModel.cc sw_models/_sentLengthModel.cc	\
sw_models/SentenceHandler.cc sw_models/LightSentenceHandler.cc		\
sw_models/IncrLexTable.cc sw_models/IncrIbm1AligModel.cc		\
sw_models/IncrHmmP0AligModel.cc sw_models/IncrHmmAligTable.cc		\
sw_models/IncrHmmAligModel.cc sw_models/DoubleMatrix.cc			\
sw_models/aSourceHmm.cc sw_models/aSource.cc				\
sw_models/anjm1ip_anjiMatrix.cc sw_models/anjiMatrix.cc

if CASMACAT_LIB_ENABLED
casmacat_aligner_h= sw_models/ThotHmmAligner.h	\
sw_models/ThotHmmAlignerFactory.h
casmacat_aligner_defs= sw_models/ThotHmmAligner.cc	\
sw_models/ThotHmmAlignerFactory.cc

casmacat_confid_h= sw_models/ThotIbmMaxConfid.h	\
sw_models/ThotIbmMaxConfidFactory.h
casmacat_confid_defs= sw_models/ThotIbmMaxConfid.cc	\
sw_models/ThotIbmMaxConfidFactory.cc
else
casmacat_alig_h= 
casmacat_alig_defs=

casmacat_confid_h= 
casmacat_confid_defs=
endif

phrase_models_h= phrase_models/WbaIncrPhraseModel.h			\
phrase_models/_wbaIncrPhraseModel.h					\
phrase_models/VecUnsignedIntSortCriterion.h				\
phrase_models/TrgSegmLenTable.h phrase_models/TrgCutsTable.h		\
phrase_models/SrfNodeKey.h phrase_models/SrfNodeInfoMap.h		\
phrase_models/SrfNodeInfo.h phrase_models/SrfBisegm.h			\
phrase_models/SrcSegmLenTable.h phrase_models/SentSegmentation.h	\
phrase_models/SegLenTable.h phrase_models/PhraseTransTableNodeData.h	\
phrase_models/PhraseTableLog.h phrase_models/PhraseTable.h		\
phrase_models/PhraseSortCriterion.h phrase_models/PhrasePairInfo.h	\
phrase_models/PhrasePair.h phrase_models/PhraseId.h			\
phrase_models/PhraseExtractParameters.h					\
phrase_models/PhraseExtractionTable.h					\
phrase_models/PhraseExtractionCell.h phrase_models/PhraseDictLog.h	\
phrase_models/PhraseDict.h phrase_models/PhraseDefs.h			\
phrase_models/PhraseCountsLog.h phrase_models/PhraseCounts.h		\
phrase_models/_incrPhraseModel.h phrase_models/CellID.h			\
phrase_models/CellAlignment.h phrase_models/Cache_lct_.h		\
phrase_models/Cache_ct_.h phrase_models/BpSetInfo.h			\
phrase_models/BpSet.h phrase_models/Bisegm.h				\
phrase_models/BasePhraseTable.h phrase_models/BasePhraseModel.h		\
phrase_models/BaseIncrPhraseModel.h					\
phrase_models/BaseCountPhraseModel.h phrase_models/AlignmentExtractor.h	\
phrase_models/AlignmentContainer.h phrase_models/AligInfo.h
phrase_models_defs= phrase_models/WbaIncrPhraseModel.cc			\
phrase_models/_wbaIncrPhraseModel.cc phrase_models/TrgSegmLenTable.cc	\
phrase_models/TrgCutsTable.cc phrase_models/SrfNodeKey.cc		\
phrase_models/SrfNodeInfoMap.cc phrase_models/SrcSegmLenTable.cc	\
phrase_models/SegLenTable.cc phrase_models/PhraseTableLog.cc		\
phrase_models/PhraseTable.cc phrase_models/PhraseExtractionTable.cc	\
phrase_models/PhraseDictLog.cc phrase_models/PhraseDict.cc		\
phrase_models/PhraseCountsLog.cc phrase_models/PhraseCounts.cc		\
phrase_models/_incrPhraseModel.cc phrase_models/Cache_lct_.cc		\
phrase_models/Cache_ct_.cc phrase_models/BpSet.cc			\
phrase_models/BasePhraseModel.cc phrase_models/BaseIncrPhraseModel.cc	\
phrase_models/AlignmentExtractor.cc phrase_models/AlignmentContainer.cc

smt_preproc_h= smt_preproc/SmtPreprocDefs.h smt_preproc/BasePrePosProcessor.h
smt_preproc_defs= 

error_correction_h= error_correction/WordGraphStateData.h		\
error_correction/WordGraph.h error_correction/WordGraphArcId.h		\
error_correction/WordGraphArc.h error_correction/WordAndCharLevelOps.h	\
error_correction/WgProcessorForAnlp.h error_correction/WgHandler.h	\
error_correction/RejectedWordsSet.h error_correction/PrefAlignInfo.h	\
error_correction/PfsmEcm.h error_correction/PfsmEcmForWg.h		\
error_correction/PfsmEcmForWgEsi.h					\
error_correction/NonPbEcModelForNbUcat.h				\
error_correction/NbSearchStack.h error_correction/NbSearchHyp.h		\
error_correction/NbestCorrections.h error_correction/HypStateIndex.h	\
error_correction/_editDist.h error_correction/EditDistForVecString.h	\
error_correction/EditDistForVec.h error_correction/EditDistForStr.h	\
error_correction/_editDistBasedEcm.h					\
error_correction/BaseWgProcessorForAnlp.h				\
error_correction/BaseErrorCorrectingModel.h				\
error_correction/BaseEditDist.h error_correction/BaseEcModelForNbUcat.h	\
error_correction/BaseEcmForWg.h
error_correction_defs= error_correction/WordGraph.cc			\
error_correction/WgHandler.cc error_correction/PfsmEcmForWg.cc		\
error_correction/PfsmEcm.cc error_correction/NonPbEcModelForNbUcat.cc	\
error_correction/NbSearchStack.cc					\
error_correction/EditDistForVecString.cc				\
error_correction/EditDistForStr.cc					\
error_correction/_editDistBasedEcm.cc					\
error_correction/BaseErrorCorrectingModel.cc

downhill_simplex_h= downhill_simplex/step_by_step_dhs.h
downhill_simplex_defs= downhill_simplex/step_by_step_dhs.c

stack_dec_h= stack_dec/WordPredictor.h stack_dec/WordPenaltyModel.h	\
stack_dec/WgUncoupledAssistedTrans.h stack_dec/UserNameToUserIdMap.h	\
stack_dec/TreatCovProblemsPars.h stack_dec/ThotMtFactoryInitPars.h	\
stack_dec/ThotMtFactory.h stack_dec/ThotMtEngine.h			\
stack_dec/ThotImtSession.h stack_dec/ThotImtFactoryInitPars.h		\
stack_dec/ThotImtFactory.h stack_dec/ThotImtEngine.h			\
stack_dec/ThotDecoderUserPars.h stack_dec/ThotDecoderState.h		\
stack_dec/ThotDecoderPerUserVars.h stack_dec/ThotDecoder.h		\
stack_dec/ThotDecoderCommonVars.h stack_dec/ThotDecoderClient.h		\
stack_dec/SwModelPars.h stack_dec/SwModelInfo.h				\
stack_dec/StackDecWgProcessorForAnlpTypes.h				\
stack_dec/StackDecSwModelTypes.h stack_dec/StackDecPbModelTypes.h	\
stack_dec/_stack_decoder_statistics.h stack_dec/_stackDecoderRec.h	\
stack_dec/_stackDecoder.h stack_dec/StackDecLmTypes.h			\
stack_dec/StackDecEcModelTypes.h					\
stack_dec/StackDecEcModelForNbUcatTypes.h				\
stack_dec/SourceSegmentation.h stack_dec/SmtStack.h			\
stack_dec/_smtStack.h stack_dec/SmtMultiStackRec.h			\
stack_dec/_smtMultiStack.h stack_dec/SmtModelTypes.h			\
stack_dec/_smtModel.h stack_dec/SmtDefs.h stack_dec/ScoreCompDefs.h	\
stack_dec/_phrSwTransModel.h stack_dec/PhrScoreInfo.h			\
stack_dec/PhrNbestTransTableRefKey.h stack_dec/PhrNbestTransTableRef.h	\
stack_dec/PhrNbestTransTablePrefKey.h					\
stack_dec/PhrNbestTransTablePref.h stack_dec/PhrNbestTransTable.h	\
stack_dec/PhrLocalSwLiTmHypRec.h stack_dec/PhrLocalSwLiTm.h		\
stack_dec/PhrHypState.h stack_dec/PhrHypNumcovJumpsEqClassF.h		\
stack_dec/PhrHypNumcovJumps01EqClassF.h stack_dec/PhrHypEqClassF.h	\
stack_dec/PhrHypData.h stack_dec/PhrasePairCacheTable.h			\
stack_dec/PhraseModelPars.h stack_dec/PhraseModelInfo.h			\
stack_dec/_phraseHypothesisRec.h stack_dec/_phraseHypothesis.h		\
stack_dec/PhraseCacheTable.h stack_dec/_phraseBasedTransModel.h		\
stack_dec/OnlineTrainingPars.h stack_dec/NgramCacheTable.h		\
stack_dec/_nbUncoupledAssistedTrans.h stack_dec/MultiStackTypes.h	\
stack_dec/multi_stack_decoder_rec.h stack_dec/LangModelPars.h		\
stack_dec/LangModelInfo.h stack_dec/HypStateDict.h			\
stack_dec/HypStateDictData.h stack_dec/HypSortCriterion.h		\
stack_dec/client_server_defs.h stack_dec/CatDefs.h stack_dec/bleu.h	\
stack_dec/BaseStackDecoder.h stack_dec/BaseSmtStack.h			\
stack_dec/BaseSmtMultiStack.h stack_dec/BaseSmtModel.h			\
stack_dec/BasePhraseHypothesisRec.h stack_dec/BasePhraseHypothesis.h	\
stack_dec/BasePbTransModelStats.h stack_dec/BasePbTransModel.h		\
stack_dec/BaseHypState.h stack_dec/BaseHypothesisRec.h			\
stack_dec/BaseHypothesis.h stack_dec/BaseAssistedTrans.h		\
stack_dec/AssistedTransTypes.h stack_dec/_assistedTrans.h
stack_dec_defs= stack_dec/WordPredictor.cc				\
stack_dec/WordPenaltyModel.cc stack_dec/UserNameToUserIdMap.cc		\
stack_dec/ThotMtFactory.cc stack_dec/ThotMtEngine.cc			\
stack_dec/ThotImtSession.cc stack_dec/ThotImtFactory.cc			\
stack_dec/ThotImtEngine.cc stack_dec/ThotDecoderClient.cc		\
stack_dec/ThotDecoder.cc stack_dec/PhrScoreInfo.cc			\
stack_dec/PhrNbestTransTableRefKey.cc					\
stack_dec/PhrNbestTransTablePrefKey.cc stack_dec/PhrLocalSwLiTm.cc	\
stack_dec/PhrHypState.cc stack_dec/PhrHypNumcovJumpsEqClassF.cc		\
stack_dec/PhrHypNumcovJumps01EqClassF.cc stack_dec/PhrHypEqClassF.cc	\
stack_dec/bleu.cc stack_dec/BaseHypState.cc

if CASMACAT_LIB_ENABLED
casmacat_engines_h= stack_dec/UserNameToUserIdMap.h		\
stack_dec/ThotMtEngine.h stack_dec/ThotMtFactoryInitPars.h	\
stack_dec/ThotMtFactory.h stack_dec/ThotImtEngine.h		\
stack_dec/ThotImtSession.h stack_dec/ThotImtFactoryInitPars.h	\
stack_dec/ThotImtFactory.h
casmacat_engines_defs= stack_dec/UserNameToUserIdMap.cc	\
stack_dec/ThotMtFactory.cc stack_dec/ThotMtEngine.cc	\
stack_dec/ThotImtSession.cc stack_dec/ThotImtFactory.cc	\
stack_dec/ThotImtEngine.cc
else
casmacat_engines_h=
casmacat_engines_defs=
endif

thot_sources= $(common_src_h) $(nlp_common_h) $(nlp_common_defs)	\
$(incr_models_h) $(incr_models_defs) $(sw_models_h) $(sw_models_defs)	\
$(phrase_models_h) $(phrase_models_defs) $(smt_preproc_h)		\
$(smt_preproc_defs) $(error_correction_h) $(error_correction_defs)	\
$(downhill_simplex_h) $(downhill_simplex_defs) $(stack_dec_h)		\
$(stack_dec_defs)

# programs
thot_ilm_perp_SOURCES = incr_models/thot_ilm_perp.cc
thot_ilm_perp_LDFLAGS = libthot.la

thot_calc_swm_lgprob_SOURCES = sw_models/thot_calc_swm_lgprob.cc
thot_calc_swm_lgprob_LDFLAGS = libthot.la

thot_gen_sw_model_SOURCES = sw_models/thot_gen_sw_model_pars.h	\
sw_models/thot_gen_sw_model.cc
thot_gen_sw_model_LDFLAGS = libthot.la

thot_sort_bin_ilextable_SOURCES = sw_models/thot_sort_bin_ilextable.cc
thot_sort_bin_ilextable_LDFLAGS = libthot.la

thot_sort_bin_ihmmatable_SOURCES = sw_models/thot_sort_bin_ihmmatable.cc
thot_sort_bin_ihmmatable_LDFLAGS = libthot.la

thot_sort_bin_iibm2atable_SOURCES = sw_models/thot_sort_bin_iibm2atable.cc
thot_sort_bin_iibm2atable_LDFLAGS = libthot.la

thot_merge_bin_ilextable_SOURCES = sw_models/thot_merge_bin_ilextable.cc
thot_merge_bin_ilextable_LDFLAGS = libthot.la

thot_merge_bin_ihmmatable_SOURCES = sw_models/thot_merge_bin_ihmmatable.cc
thot_merge_bin_ihmmatable_LDFLAGS = libthot.la

thot_merge_bin_iibm2atable_SOURCES = sw_models/thot_merge_bin_iibm2atable.cc
thot_merge_bin_iibm2atable_LDFLAGS = libthot.la

thot_gen_bin_lex_filter_info_SOURCES = sw_models/thot_gen_bin_lex_filter_info.cc
thot_gen_bin_lex_filter_info_LDFLAGS = libthot.la

thot_filter_bin_ilextable_SOURCES = sw_models/thot_filter_bin_ilextable.cc
thot_filter_bin_ilextable_LDFLAGS = libthot.la

thot_prune_bin_ilextable_SOURCES = sw_models/thot_prune_bin_ilextable.cc
thot_prune_bin_ilextable_LDFLAGS = libthot.la

thot_alig_op_SOURCES = phrase_models/thot_alig_op.cc
thot_alig_op_LDFLAGS = libthot.la

thot_gen_phr_model_SOURCES = phrase_models/thot_gen_phr_model.cc
thot_gen_phr_model_LDFLAGS = libthot.la

thot_wg_proc_SOURCES = error_correction/thot_wg_proc_pars.h	\
error_correction/thot_wg_proc.cc
thot_wg_proc_LDFLAGS = libthot.la

thot_dhs_step_by_step_min_SOURCES = downhill_simplex/thot_dhs_step_by_step_min.cc
thot_dhs_step_by_step_min_LDFLAGS = libthot.la

thot_dec_ms_SOURCES = stack_dec/thot_dec_ms.cc
thot_dec_ms_LDFLAGS = libthot.la

thot_aligner_SOURCES = stack_dec/thot_aligner.cc
thot_aligner_LDFLAGS = libthot.la

thot_dec_client_SOURCES = stack_dec/thot_dec_client_pars.h	\
stack_dec/thot_dec_client.cc
thot_dec_client_LDFLAGS = libthot.la

thot_dec_server_SOURCES = stack_dec/thot_dec_server_pars.h	\
stack_dec/thot_dec_server.cc
thot_dec_server_LDFLAGS = libthot.la

thot_calc_bleu_SOURCES = stack_dec/thot_calc_bleu.cc
thot_calc_bleu_LDFLAGS = libthot.la

if CASMACAT_LIB_ENABLED
# test_casmacat_engines_SOURCES = stack_dec/test_casmacat_engines.cc
# test_casmacat_engines_LDFLAGS = libthot_casmacat.la libthot.la
endif

# include headers
include_HEADERS = $(common_src_h) $(nlp_common_h) $(incr_models_h)	\
$(sw_models_h) $(phrase_models_h) $(smt_preproc_h)			\
$(error_correction_h) $(downhill_simplex_h) $(stack_dec_h)		\
$(casmacat_engines_h) $(casmacat_aligner_h) $(casmacat_confid_h)

# libraries
libthot_la_SOURCES= $(thot_sources) 
libthot_la_LIBADD= $(ZLIB) $(LGMP)

libthot_casmacat_la_SOURCES= $(casmacat_engines_h)			\
$(casmacat_engines_defs) $(casmacat_aligner_h) $(casmacat_aligner_defs)	\
$(casmacat_confid_h) $(casmacat_confid_defs)
libthot_casmacat_la_LIBADD= $(ZLIB) $(LGMP)
