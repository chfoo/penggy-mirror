;;
;; Copyright (C) 2002  Jean-Charles Salzeber <jc@varspool.net>
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
;; Scheme script for logon into GlobalNet servers                   ;;
;;                                                                  ;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(define (GlobalRequestAttn tries)
  (if (> tries 3) 
      (chat-failure)

      (chat-send "...\r")
      (chat-try 25 
	      '("SITA NETWORK"  (GlobalSetupEnvironment 0))
	      '("ANSNET"        (chat-failure))
	      '("SATURN.BBN"    (chat-failure))
	      '("SPRINT-IP"     (chat-failure))
	      '("TERMINAL="     (chat-failure))
	      '("TERMINAL ="    (chat-failure))
	      '("\r\n@"         (chat-failure))
	      '("\r\n ?"        (chat-failure))
	      '("LOCAL"         (chat-failure))
	      '("ERROR"         (chat-failure))
	      '("NO CARRIER"    (chat-failure))
	      '(else            (GlobalRequestAttn (+ tries 1))))))

(define (GlobalSetupEnvironment)
  (chat-send "SET 1:0,2:0,21:0\r")
  (sleep 1)
  (GlobalTalkToNetwork))

(define (GlobalTalkToNetwork tries)
  (if (> (tries) 4) 
      (chat-failure)

      (sleep 1)
      (chat-send "NUI 22500001\r")
      (chat-try 10 
	      '("XXXXXX"     (GlobalReqAuth))
	      '("\r\n ?"     (chat-failure))
	      '("ERROR"      (chat-failure))
	      '("NO CARRIER" (chat-failure))
	      '(else         (GlobalTalkToNetwork (+ tries 1))))))
                              
(define (GlobalReqAuth tries)
  (sleep 1)
  (chat-send "OPXY9F\r")
  (chat-try 10 
    '("ACTIVE"     (GlobalConnect))
    '("\r\n ?"     (chat-failure))
    '("ERROR"      (chat-failure))
    '("NO CARRIER" (chat-failure))
    '(else         (GlobalTalkToNetwork tries))))

(define (GlobalConnect)
  (sleep 1)
  (chat-send "LINE(256)9001131,windows 0001\r")
  (chat-try 23 
    '("CONNECTED"         (chat-success))
    '("OPEN"              (chat-success))
    '("NOT RE"            (chat-failure))
    '("NOT AVAIL"         (chat-failure))
    '("NO CONNECT"        (chat-failure))
    '("BAD PASSWORD"      (chat-failure))
    '("LOGIN INVALID"     (chat-failure))
    '("REJECT"            (chat-failure))
    '("LOCAL"             (chat-failure))
    '("NOT PERMIT"        (chat-failure))
    '("CONGEST"           (chat-failure))
    '("NOT OPERATING"     (chat-failure))
    '("BUSY"              (chat-failure))
    '("DISCONNECT"        (chat-failure))
    '("PROBLEM"           (chat-failure))
    '("NOT AL"            (chat-failure))
    '("NOT IN S"          (chat-failure))
    '("REMOTE DIRECTIVE"  (chat-failure))
    '("\r\n ?"            (chat-failure))
    '("ERROR"             (chat-failure))
    '("NO CARRIER"        (chat-failure))
    '(else                (chat-failure))))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Main entry point
(define (chat-connect)
  (sleep 5)
  (GlobalRequestAttn 0))
