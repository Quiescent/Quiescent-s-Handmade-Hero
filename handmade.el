;;; handmade --- A collection of functions for editing this project -*- lexical-binding: t; -*-

;;; Commentary:

;;; Code:

(require 'project)

(defun handmade-debug ()
  "Run and debug handmade."
  (interactive)
  (let* ((root-dir          (car (project-roots (project-current))))
         (default-directory root-dir))
    (gdb (format "gdb -i=mi %sbin/handmade" root-dir))
    (gdb-many-windows)))

(provide 'handmade)
;;; handmade ends here
