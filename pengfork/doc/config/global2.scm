;;
;; Copyright (C) 2002-2003  Jean-Charles Salzeber <chupa@penggy.org>
;;
;; This file is part of penggy.
;;
;; This program is free software; you can redistribute it and/or
;; modify it under the terms of the GNU General Public License
;; as published by the Free Software Foundation; either version 2
;; of the License, or (at your option) any later version.
;; 
;; This program is distributed in the hope that it will be useful,
;; but WITHOUT ANY WARRANTY; without even the implied warranty of
;; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
;; GNU General Public License for more details.
;; 
;; You should have received a copy of the GNU General Public License
;; along with this program; if not, write to the Free Software
;; Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
;; 02111-1307, USA.
;;                
;; $Id$
;;


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;                                                                  ;;
;; Scheme script for logon into Globalnet Plus servers              ;;
;;                                                                  ;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;


(define (talk-to-network)
  (chat-send "aoluser@aol.com\r")
  (chat-try 20
	  '("Password"   (begin
		         (chat-send "aolpw\r")
		         (chat-try 60
			         '("Connected"      (chat-success))
			         '("Open"           (chat-success))
			         '("Unavailable"    (chat-failure))
			         '("Connect Failed" (chat-failure))
			         '("Not Available"  (chat-failure))
			         '("Unreachable"    (chat-failure))
			         '("No Connection"  (chat-failure))
			         '("Bad Password"   (chat-failure))
			         '("Failed"         (chat-failure))
			         '("Login Invalid"  (chat-failure))
			         '("Invalid User"   (chat-failure))
			         '("Error in"       (chat-failure))
			         '("Server Timeout" (chat-failure))
			         '("NO CARRIER"     (chat-failure))
			         '(else             (chat-failure)))))
	  '("NO CARRIER" (chat-failure))
	  '(else         (chat-failure))))

(define (talk-to-livingston)
  (chat-send "aoluser@aol.com\r")
  (chat-try 20
	  '("Password"   (begin
		         (chat-send "aolpw\r")
		         (chat-try 10
			         '("Unavailable"    (chat-failure))
			         '("Connect Failed" (chat-failure))
			         '("Not Available"  (chat-failure))
			         '("Unreachable"    (chat-failure))
			         '("No Connection"  (chat-failure))
			         '("Bad Password"   (chat-failure))
			         '("Failed"         (chat-failure))
			         '("Login Invalid"  (chat-failure))
			         '("Error in"       (chat-failure))
			         '("Server Timeout" (chat-failure))
			         '("NO CARRIER"     (chat-failure))
			         '(else             (chat-success)))))
	  '("NO CARRIER" (chat-failure))
	  '(else         (chat-failure))))



;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Main entry point
(define (chat-connect)
  (chat-try 20
	  '("Login"      (talk-to-network))
	  '("Username"   (talk-to-network))
	  '("Livingston" (talk-to-livingston))
	  '("NO CARRIER" (chat-failure))
	  '(else         (chat-failure))))
