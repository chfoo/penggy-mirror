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

(define (request-attn tries)
  (if (> tries 3) 
      (chat-failure)

      (chat-send "...\r")
      (chat-try 25 
	      '("SITA NETWORK"  (setup-environment 0))
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
	      '(else            (request-attn (+ tries 1))))))

(define (setup-snvironment)
  (chat-send "SET 1:0,2:0,21:0\r")
  (sleep 1)
  (talk-to-network))

(define (talk-to-network tries)
  (if (> (tries) 4) 
      (chat-failure)

      (sleep 1)
      (chat-send "NUI 22500001\r")
      (chat-try 10 
	      '("XXXXXX"     (req-auth (+ tries 1)))
	      '("\r\n ?"     (chat-failure))
	      '("ERROR"      (chat-failure))
	      '("NO CARRIER" (chat-failure))
	      '(else         (talk-to-network (+ tries 1))))))
                              
(define (req-auth tries)
  (sleep 1)
  (chat-send "OPXY9F\r")
  (chat-try 10 
    '("ACTIVE"     (aol-connect))
    '("\r\n ?"     (chat-failure))
    '("ERROR"      (chat-failure))
    '("NO CARRIER" (chat-failure))
    '(else         (talk-to-network tries))))

(define (aol-connect)
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
  (request-attn 0))
