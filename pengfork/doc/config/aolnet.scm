;;
;; Copyright (C) 2002-2003  Jean-Charles Salzeber <jc@varspool.net>
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
;; Scheme script for logon into AOLnet servers                      ;;
;;                                                                  ;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; general end function
(define (aol-connect) 
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



;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Login into an ANS server type
(define (ans-login)
  (chat-try 20
	  '("login"      (begin
		         (chat-send "aol\r") 
		         (aol-connect)))
	  '("NO CARRIER" (chat-failure))
	  '(else         (chat-failure))))



;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Login into a BBN server type
(define (bbn-login2)
  (chat-send "aolnet\r")
  (chat-try 20
	  '("Password"   (begin
		         (chat-send "A0L2aNet\r") 
		         (aol-connect)))
	  '("NO CARRIER" (chat-failure))
	  '(else         (chat-failure))))

(define (bbn-login)
  (chat-try 20
	  '("login"      (bbn-login2))
	  '("NO CARRIER" (chat-failure))
	  '(else         (chat-failure))))



;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Login into a Sprint server type
(define (sprint-login2)
  (chat-send "aol\r")
  (chat-try 20
	  '("Password"   (begin
		         (chat-send "aol\r") 
		         (aol-connect)))
	  '("NO CARRIER" (chat-failure))
	  '(else         (chat-failure))))

(define (sprint-login)
  (chat-try 20
	  '("Username"   (sprint-login2))
	  '("login"      (sprint-login2))
	  '("NO CARRIER" (chat-failure))
	  '(else         (chat-failure))))



;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Main entry point, it try to determine server type
(define (chat-connect) 
  (chat-try 20 
	  '("ANSNet"     (ans-login))
	  '("UU.Net"     (ans-login))
	  '("Saturn.BBN" (bbn-login))
	  '("Sprint-IP"  (sprint-login))
	  '("UQKT1"      (ans-login))
	  '("UQKT2"      (sprint-login))
	  '("Connected"  (chat-success))
	  '("NO CARRIER" (chat-failure))
	  '(else         (chat-failure))))
