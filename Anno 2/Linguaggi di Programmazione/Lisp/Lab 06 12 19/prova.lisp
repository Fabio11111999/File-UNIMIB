;;;; -*- Mode: Lisp -*-

(defun fact (x) 
  (if (eq x 0)
      1
    (* (fact (- x 1)) x)))