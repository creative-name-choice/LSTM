// tests.c
#include "feedforward.h"
#include "feedback.h"
#include "printing.h"

int main(int argc, char *argv[]) {
  // TEST 1:
  LSTM_type *LSTM = make_LSTM(4, 1);

  // TEST 4/5:
  // Xt_i:
  long double inputs[11][4][1] = {
    {{0},{0},{0},{0}}, // End of input
    {{0},{0},{0},{1}}, // Dummy input
    {{0},{0},{0},{1}}, // Dummy input
    {{0},{0},{0},{1}}, // Dummy input
    {{0},{0},{0},{1}}, // Dummy input
    {{0},{0},{1},{0}}, // Output trigger
    {{0},{0},{1},{1}}, // First possibility:  NAND(0, 0) = 1
    {{0},{1},{1},{1}}, // Second possibility: NAND(0, 1) = 1
    {{1},{0},{1},{1}}, // Third possibility:  NAND(1, 0) = 1
    {{1},{1},{1},{1}}, // Fourth possibility: NAND(1, 1) = 0
    {{0},{0},{0},{1}}  // Dummy input
  };

/* Yt_k:
(((1 1)
  (1 1)
  (1 1)
  (1 1))
 ((


(((0 0)
  (0 0)
  (0 0)
  (0 0))
 ((0 0)
  (0 0)
  (0 0)
  (0 0))
 ((0 0)
  (0 0)
  (0 0)
  (0 0))
 ((0 0)
  (0 0)
  (0 0)
  (0 0))
 ((0 0)
  (0 0)
  (0 0)
  (0 0))
 ((0 1)
  (0 1)
  (1 0)
  (1 0))
 ((0 1)
  (1 0)
  (1 0)
  (1 0))
 ((1 0)
  (0 1)
  (1 0)
  (1 0))
 ((1 0)
  (1 0)
  (1 0)
  (1 0))
 ((1 1)
  (1 1)
  (1 1)
  (1 1))
 ((1 1)
  (1 1)
  (1 1)
  (1 1)))
*/
  long double outputs[11][1][2] = {
    {{1, 1}},
    {{0, 1}},
    {{1, 0}},
    {{1, 0}},
    {{1, 0}},
    {{0, 0}},
    {{0, 0}},
    {{0, 0}},
    {{0, 0}},
    {{0, 0}}
  };

  // TEST 1:
  NOT_USED(argc);
  NOT_USED(argv);

  /* TEST 2:
  push(LSTM, At_iota, dot_product(first(LSTM, Xt_i), first(LSTM, Wi_iota)));
  */

  /* TEST 3:
  push(LSTM, St_c, 
    sum(2, 
      product(2, 
        matrix_tanh(first(LSTM, At_c)), 
        first(LSTM, Bt_iota)), 
      product(2, 
        second(LSTM, St_c), 
        first(LSTM, Bt_phi))));
  */

  // TEST 4:
  feedforward_once(LSTM);

  // TEST 5:
  //feedback_once(LSTM);

  // TEST 1:
  print_LSTM(LSTM);

  // TEST 1:
  LSTM = destroy_LSTM(LSTM);
  return 0;
}