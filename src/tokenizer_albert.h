#pragma once

#include "config_utils.h"
#include "sentencepiece_processor.h"
#include "tokenizer_base.h"

class TokenizerAlbert : TokenizerBase {
public:
  TokenizerAlbert(const char *pretrained_dir);
  TokenizerAlbert(TransformersTokenizerConfigs configs,
                  const char *spmodel_path);

  tpenc encode(string &text_a, string &text_b, bool add_special_tokens,
               size_t max_length, size_t stride,
               const char *truncation_strategy, bool pad_to_max_length);

private:
  std::shared_ptr<sentencepiece::SentencePieceProcessor> processor_;
};
