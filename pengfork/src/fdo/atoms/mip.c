/*
 * Copyright (C) 2002  Jean-Charles Salzeber <jc@varspool.net>
 *
 * This file is part of penggy.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
 * 02111-1307, USA.
 *
 * $Id$
 *
 */

#if HAVE_CONFIG_H
# include "config.h"
#endif

#if STDC_HEADERS
# include <stdlib.h>
# include <stddef.h>
#else
# if HAVE_STDLIB_H
#  include <stdlib.h>
# endif
#endif

#include "fdo/atoms.h"


const atomdef_t mip_atom_tab[] = {
  {"mip-start-message"          , MIP_START_MESSAGE          , raw},
  {"mip-header-complete"        , MIP_HEADER_COMPLETE        , raw},
  {"mip-end-message"            , MIP_END_MESSAGE            , raw},
  {"mip-header-accepted"        , MIP_HEADER_ACCEPTED        , raw},
  {"mip-message-accepted"       , MIP_MESSAGE_ACCEPTED       , raw},
  {"mip-error"                  , MIP_ERROR                  , multi},
  {"mip-abort"                  , MIP_ABORT                  , raw},
  {"mip-start-block"            , MIP_START_BLOCK            , raw},
  {"mip-end-block"              , MIP_END_BLOCK              , raw},
  {"mip-addressee"              , MIP_ADDRESSEE              , raw},
  {"mip-subject"                , MIP_SUBJECT                , raw},
  {"mip-text"                   , MIP_TEXT                   , raw},
  {"mip-data"                   , MIP_DATA                   , raw},
  {"mip-message-id"             , MIP_MESSAGE_ID             , raw},
  {"mip-author"                 , MIP_AUTHOR                 , raw},
  {"mip-message-date"           , MIP_MESSAGE_DATE           , raw},
  {"mip-message-datestr"        , MIP_MESSAGE_DATESTR        , raw},
  {"mip-forward"                , MIP_FORWARD                , raw},
  {"mip-attr-addressee-type"    , MIP_ATTR_ADDRESSEE_TYPE    , raw},
  {"mip-attr-data-type"         , MIP_ATTR_DATA_TYPE         , raw},
  {"mip-attr-file-name"         , MIP_ATTR_FILE_NAME         , raw},
  {"mip-attr-file-size"         , MIP_ATTR_FILE_SIZE         , raw},
  {"mip-attr-file-type"         , MIP_ATTR_FILE_TYPE         , raw},
  {"mip-attr-file-create-date"  , MIP_ATTR_FILE_CREATE_DATE  , raw},
  {"mip-attr-message-type"      , MIP_ATTR_MESSAGE_TYPE      , raw},
  {"mip-bool-return-receipt"    , MIP_BOOL_RETURN_RECEIPT    , raw},
  {"mip-attr-list-type"         , MIP_ATTR_LIST_TYPE         , raw},
  {"mip-addressee-comment"      , MIP_ADDRESSEE_COMMENT      , raw},
  {"mip-action-command"         , MIP_ACTION_COMMAND         , raw},
  {"mip-set-calling-form-id"    , MIP_SET_CALLING_FORM_ID    , raw},
  {"mip-end-of-data"            , MIP_END_OF_DATA            , raw},
  {"mip-scheduler-mode"         , MIP_SCHEDULER_MODE         , raw},
  {"mip-flip-it"                , MIP_FLIP_IT                , raw},
  {"mip-edit-outbox"            , MIP_EDIT_OUTBOX            , raw},
  {"mip-preset-form-title"      , MIP_PRESET_FORM_TITLE      , raw},
  {"mip-get-active-name-count"  , MIP_GET_ACTIVE_NAME_COUNT  , raw},
  {"mip-is-name-active"         , MIP_IS_NAME_ACTIVE         , str},
  {"mip-set-name-active"        , MIP_SET_NAME_ACTIVE        , str},
  {"mip-clear-active-names"     , MIP_CLEAR_ACTIVE_NAMES     , raw},
  {"mip-set-forward-ref"        , MIP_SET_FORWARD_REF        , dword},
  {"mip-attr-folder"            , MIP_ATTR_FOLDER            , str},
  {"mip-abort-all"              , MIP_ABORT_ALL              , raw},
  {"mip-preset-message-id"      , MIP_PRESET_MESSAGE_ID      , dword},
  {"mip-change-message-status"  , MIP_CHANGE_MESSAGE_STATUS  , dword},
  {"mip-attr-encoding-format"   , MIP_ATTR_ENCODING_FORMAT   , raw},
  {"mip-bool-everyone-invisible", MIP_BOOL_EVERYONE_INVISIBLE, bool},
  {"mip-reply-to"               , MIP_REPLY_TO               , str},
  {"mip-do-not-reply-to"        , MIP_DO_NOT_REPLY_TO        , str},
  {"mip-read-mail"              , MIP_READ_MAIL              , dword},
  {"mip-bool-will-ack"          , MIP_BOOL_WILL_ACK          , bool},
  {"mip-bool-inet-quoting"      , MIP_BOOL_INET_QUOTING      , bool},
  {"mip-start-errors"           , MIP_START_ERRORS           , raw},
  {"mip-end-errors"             , MIP_END_ERRORS             , raw},
  {"mip-display-mail-form"      , MIP_DISPLAY_MAIL_FORM      , dword},
  {"mip-delete-online-lists"    , MIP_DELETE_ONLINE_LISTS    , raw},
  {"mip-attr-message-size"      , MIP_ATTR_MESSAGE_SIZE      , dword},
  {"mip-error-code"             , MIP_ERROR_CODE             , dword},
  {"mip-folder-name"            , MIP_FOLDER_NAME            , str},
  {"mip-folder-password"        , MIP_FOLDER_PASSWORD        , str},
  {"mip-transaction-type"       , MIP_TRANSACTION_TYPE       , dword},
  {"mip-bool-more-to-come"      , MIP_BOOL_MORE_TO_COME      , bool},
  {"mip-sender-id"              , MIP_SENDER_ID              , str},
  {"mip-get-next-typed"         , MIP_GET_NEXT_TYPED         , dword},
  {"mip-get-prev-typed"         , MIP_GET_PREV_TYPED         , dword},
  {"mip-spell-check-send-now"   , MIP_SPELL_CHECK_SEND_NOW   , raw},
  {"mip-spell-check-send-later" , MIP_SPELL_CHECK_SEND_LATER , raw},
  {"mip-attr-embed-object"      , MIP_ATTR_EMBED_OBJECT      , raw},
  {"mip-email-id-p1"            , MIP_EMAIL_ID_P1            , raw},
  {"mip-email-id-p2"            , MIP_EMAIL_ID_P2            , raw},
  {"mip-email-id-alias"         , MIP_EMAIL_ID_ALIAS         , raw},
  {"mip-exp-class-id"           , MIP_EXP_CLASS_ID           , word},
  {"mip-exp-class-name"         , MIP_EXP_CLASS_NAME         , str},
  {"mip-filter-active"          , MIP_FILTER_ACTIVE          , bool},
  {"mip-filter-name"            , MIP_FILTER_NAME            , str},
  {"mip-filter-class-id"        , MIP_FILTER_CLASS_ID        , bool},
  {"mip-filter-number"          , MIP_FILTER_NUMBER          , word},
  {"mip-folder-id"              , MIP_FOLDER_ID              , word},
  {"mip-storage-class-id"       , MIP_STORAGE_CLASS_ID       , word},
  {"mip-storage-class-name"     , MIP_STORAGE_CLASS_NAME     , str},
  {"mip-uid-validity"           , MIP_UID_VALIDITY           , word},
  {"mip-mail-counts"            , MIP_MAIL_COUNTS            , raw},
  {"mip-view-name"              , MIP_VIEW_NAME              , str},
  {"mip-profile"                , MIP_PROFILE                , dword},
  {"mip-continue-context"       , MIP_CONTINUE_CONTEXT       , raw},
  {NULL, -1, na}
};
