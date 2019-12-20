;;;; -*- Mode: Lisp -*-

;;;; Begin of File: lab2.lisp

(defun new-tree (name &optional root)
  (if (null root)
      (list 'tree name root)
    (if (is-node root)
        (list 'tree name root))))

(defun is-tree (tree)
  (and (listp tree)
       (= (length tree) 3)
       (eq (first tree) 'tree)))

(defun tree-name (tree)
  (when (is-tree tree)
    (second tree)))

(defun tree-root (tree)
  (when (is-tree tree)
    (third tree)))

(defun new-node (key value &optional left right)
  (when key
    (list 'node key value left right)))

(defun is-node (node)
  (when node
    (and (listp node)
         (= (length node) 5)
         (eq (first node) 'node))))

(defun node-key (node)
  (when (is-node node)
    (second node)))

(defun node-value (node)
  (when (is-node node)
    (third node)))

(defun node-left (node)
  (when (is-node node)
    (fourth node)))

(defun node-right (node)
  (when (is-node node)
    (fifth node)))

(defun tree-insert (tree k v)
  (new-tree (tree-name tree)
            (node-insert (tree-root tree) k v)))

(defun node-insert (root k v)
  (if (null root)
      (new-node k v)
    (if (< k (node-key root))
        (new-node (node-key root) (node-value root) (node-insert (node-left root) k v) (node-right root))
      (new-node (node-key root) (node-value root) (node-left root) (node-insert (node-right root) k v)))))


(defun tree-search (tree k)
  (let ((n (node-search (tree-root tree) k)))
    (when n
      (values (node-value n) t))))

(defun node-search (node k) 
  (when node
    (if (= (node-key node) k)
        node
      (if (< k (node-key node))
          (node-search (node-left node) k)
        (node-search (node-right node) k)))))

;;;; End of File: lab2.lisp

