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
  {"mip_start_message"          , MIP_START_MESSAGE          , raw},
  {"mip_header_complete"        , MIP_HEADER_COMPLETE        , raw},
  {"mip_end_message"            , MIP_END_MESSAGE            , raw},
  {"mip_header_accepted"        , MIP_HEADER_ACCEPTED        , raw},
  {"mip_message_accepted"       , MIP_MESSAGE_ACCEPTED       , raw},
  {"mip_error"                  , MIP_ERROR                  , multi},
  {"mip_abort"                  , MIP_ABORT                  , raw},
  {"mip_start_block"            , MIP_START_BLOCK            , raw},
  {"mip_end_block"              , MIP_END_BLOCK              , raw},
  {"mip_addressee"              , MIP_ADDRESSEE              , raw},
  {"mip_subject"                , MIP_SUBJECT                , raw},
  {"mip_text"                   , MIP_TEXT                   , raw},
  {"mip_data"                   , MIP_DATA                   , raw},
  {"mip_message_id"             , MIP_MESSAGE_ID             , raw},
  {"mip_author"                 , MIP_AUTHOR                 , raw},
  {"mip_message_date"           , MIP_MESSAGE_DATE           , raw},
  {"mip_message_datestr"        , MIP_MESSAGE_DATESTR        , raw},
  {"mip_forward"                , MIP_FORWARD                , raw},
  {"mip_attr_addressee_type"    , MIP_ATTR_ADDRESSEE_TYPE    , raw},
  {"mip_attr_data_type"         , MIP_ATTR_DATA_TYPE         , raw},
  {"mip_attr_file_name"         , MIP_ATTR_FILE_NAME         , raw},
  {"mip_attr_file_size"         , MIP_ATTR_FILE_SIZE         , raw},
  {"mip_attr_file_type"         , MIP_ATTR_FILE_TYPE         , raw},
  {"mip_attr_file_create_date"  , MIP_ATTR_FILE_CREATE_DATE  , raw},
  {"mip_attr_message_type"      , MIP_ATTR_MESSAGE_TYPE      , raw},
  {"mip_bool_return_receipt"    , MIP_BOOL_RETURN_RECEIPT    , raw},
  {"mip_attr_list_type"         , MIP_ATTR_LIST_TYPE         , raw},
  {"mip_addressee_comment"      , MIP_ADDRESSEE_COMMENT      , raw},
  {"mip_action_command"         , MIP_ACTION_COMMAND         , raw},
  {"mip_set_calling_form_id"    , MIP_SET_CALLING_FORM_ID    , raw},
  {"mip_end_of_data"            , MIP_END_OF_DATA            , raw},
  {"mip_scheduler_mode"         , MIP_SCHEDULER_MODE         , raw},
  {"mip_flip_it"                , MIP_FLIP_IT                , raw},
  {"mip_edit_outbox"            , MIP_EDIT_OUTBOX            , raw},
  {"mip_preset_form_title"      , MIP_PRESET_FORM_TITLE      , raw},
  {"mip_get_active_name_count"  , MIP_GET_ACTIVE_NAME_COUNT  , raw},
  {"mip_is_name_active"         , MIP_IS_NAME_ACTIVE         , str},
  {"mip_set_name_active"        , MIP_SET_NAME_ACTIVE        , str},
  {"mip_clear_active_names"     , MIP_CLEAR_ACTIVE_NAMES     , raw},
  {"mip_set_forward_ref"        , MIP_SET_FORWARD_REF        , dword},
  {"mip_attr_folder"            , MIP_ATTR_FOLDER            , str},
  {"mip_abort_all"              , MIP_ABORT_ALL              , raw},
  {"mip_preset_message_id"      , MIP_PRESET_MESSAGE_ID      , dword},
  {"mip_change_message_status"  , MIP_CHANGE_MESSAGE_STATUS  , dword},
  {"mip_attr_encoding_format"   , MIP_ATTR_ENCODING_FORMAT   , raw},
  {"mip_bool_everyone_invisible", MIP_BOOL_EVERYONE_INVISIBLE, bool},
  {"mip_reply_to"               , MIP_REPLY_TO               , str},
  {"mip_do_not_reply_to"        , MIP_DO_NOT_REPLY_TO        , str},
  {"mip_read_mail"              , MIP_READ_MAIL              , dword},
  {"mip_bool_will_ack"          , MIP_BOOL_WILL_ACK          , bool},
  {"mip_bool_inet_quoting"      , MIP_BOOL_INET_QUOTING      , bool},
  {"mip_start_errors"           , MIP_START_ERRORS           , raw},
  {"mip_end_errors"             , MIP_END_ERRORS             , raw},
  {"mip_display_mail_form"      , MIP_DISPLAY_MAIL_FORM      , dword},
  {"mip_delete_online_lists"    , MIP_DELETE_ONLINE_LISTS    , raw},
  {"mip_attr_message_size"      , MIP_ATTR_MESSAGE_SIZE      , dword},
  {"mip_error_code"             , MIP_ERROR_CODE             , dword},
  {"mip_folder_name"            , MIP_FOLDER_NAME            , str},
  {"mip_folder_password"        , MIP_FOLDER_PASSWORD        , str},
  {"mip_transaction_type"       , MIP_TRANSACTION_TYPE       , dword},
  {"mip_bool_more_to_come"      , MIP_BOOL_MORE_TO_COME      , bool},
  {"mip_sender_id"              , MIP_SENDER_ID              , str},
  {"mip_get_next_typed"         , MIP_GET_NEXT_TYPED         , dword},
  {"mip_get_prev_typed"         , MIP_GET_PREV_TYPED         , dword},
  {"mip_spell_check_send_now"   , MIP_SPELL_CHECK_SEND_NOW   , raw},
  {"mip_spell_check_send_later" , MIP_SPELL_CHECK_SEND_LATER , raw},
  {"mip_attr_embed_object"      , MIP_ATTR_EMBED_OBJECT      , raw},
  {"mip_email_id_p1"            , MIP_EMAIL_ID_P1            , raw},
  {"mip_email_id_p2"            , MIP_EMAIL_ID_P2            , raw},
  {"mip_email_id_alias"         , MIP_EMAIL_ID_ALIAS         , raw},
  {"mip_exp_class_id"           , MIP_EXP_CLASS_ID           , word},
  {"mip_exp_class_name"         , MIP_EXP_CLASS_NAME         , str},
  {"mip_filter_active"          , MIP_FILTER_ACTIVE          , bool},
  {"mip_filter_name"            , MIP_FILTER_NAME            , str},
  {"mip_filter_class_id"        , MIP_FILTER_CLASS_ID        , bool},
  {"mip_filter_number"          , MIP_FILTER_NUMBER          , word},
  {"mip_folder_id"              , MIP_FOLDER_ID              , word},
  {"mip_storage_class_id"       , MIP_STORAGE_CLASS_ID       , word},
  {"mip_storage_class_name"     , MIP_STORAGE_CLASS_NAME     , str},
  {"mip_uid_validity"           , MIP_UID_VALIDITY           , word},
  {"mip_mail_counts"            , MIP_MAIL_COUNTS            , raw},
  {"mip_view_name"              , MIP_VIEW_NAME              , str},
  {"mip_profile"                , MIP_PROFILE                , dword},
  {"mip_continue_context"       , MIP_CONTINUE_CONTEXT       , raw},
  {NULL, -1, na}
};
