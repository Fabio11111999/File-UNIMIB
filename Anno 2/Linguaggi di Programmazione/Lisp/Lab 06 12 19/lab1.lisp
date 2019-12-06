;;;; -*- Mode: Lisp -*-
;;;; Begin of file: lab1.lisp
(defun fact (x) 
  (if (eq x 0)
      1
    (* (fact (- x 1)) x)))

(defun in (x l)
  (cond ((null l) NIL)
        ((eql x (first l)) l)
        ((in x (rest l)))))


(defun associa (x alist)
  (cond ((null alist) NIL)
        ((eql x (first (first alist))) (first alist))
        (T (associa x (rest alist)))))
;;;; End of File: lab1.lisp
