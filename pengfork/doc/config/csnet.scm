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
;; Scheme script for logon into CompuServe servers                  ;;
;;                                                                  ;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; general end function
(define (cs-connect) 
  (chat-try 120
	  '("Connected"      (chat-success))
	  '("Open"           (chat-success))
	  '("Unavailable"    (chat-failure))
	  '("Connect Failed" (chat-failure))
	  '("Not Available"  (chat-failure))
	  '("Unreachable"    (chat-failure))
	  '("No Connection"  (chat-failure))
	  '("Bad Password"   (chat-failure))
	  '("Login Invalid"  (chat-failure))
	  '("NO CARRIER"     (chat-failure))
	  '(else             (chat-failure))))



(define (cs-login)
  (chat-try 20
	  '("Username"   (cs-send-login))
	  '("login"      (cs-send-login))
	  '("NO CARRIER" (chat-failure))
	  '(else         (chat-failure))))

(define (cs-send-login)
  (chat-send "csn\r")
  (chat-try 20
	  '("Password"   (begin
		         (chat-send "csnet\r")
		         (cs-connect)))
	  '("NO CARRIER"     (chat-failure))
	  '(else             (chat-failure))))

(define (cs-login-nopw)
  (chat-try 20
	  '("Username"   (cs-send-login-nopw))
	  '("login"      (cs-send-login))
	  '("NO CARRIER" (chat-failure))
	  '(else         (chat-failure))))

(define (cs-send-login-nopw)
  (chat-send "csn\r")
  (cs-connect))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Main entry point, it try to determine server type
(define (chat-connect) 
  (chat-try 20 
	  '("ANSNet"     (cs-login))
	  '("UU.Net"     (cs-login))
	  '("Saturn.BBN" (cs-login))
	  '("Sprint-IP"  (cs-login))
	  '("UQKT1"      (cs-login-nopw))
	  '("UQKT2"      (cs-login))
	  '("Connected"  (chat-success))
	  '("NO CARRIER" (chat-failure))
	  '(else         (chat-failure))))
