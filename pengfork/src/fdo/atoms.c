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


const protdef_t fdoprot[] = {
  { UNI_PID     , "UNI"     , uni_atom_tab     }, 
  { MAN_PID     , "MAN"     , man_atom_tab     },
  { ACT_PID     , "ACT"     , act_atom_tab     },
  { DE_PID      , "DE"      , de_atom_tab      },
  { BUF_PID     , "BUF"     , buf_atom_tab     },
  { IDB_PID     , "IDB"     , idb_atom_tab     },
  { XFER_PID    , "XFER"    , xfer_atom_tab    },
  { FM_PID      , "FM"      , fm_atom_tab      },
  { LM_PID      , "LM"      , lm_atom_tab      },
  { CM_PID      , "CM"      , cm_atom_tab      },
  { CHAT_PID    , "CHAT"    , chat_atom_tab    },
  { VAR_PID     , "VAR"     , var_atom_tab     },
  { ASYNC_PID   , "ASYNC"   , async_atom_tab   },
  { SM_PID      , "SM"      , sm_atom_tab      },
  { IF_PID      , "IF"      , if_atom_tab      },
  { MAT_PID     , "MAT"     , mat_atom_tab     },
  { MIP_PID     , "MIP"     , mip_atom_tab     },
  { MMI_PID     , "MMI"     , mmi_atom_tab     },
  { IMGXFER_PID , "IMGXFER" , imgxfer_atom_tab },
  { IMAGE_PID   , "IMAGE"   , image_atom_tab   },
  { CHART_PID   , "CHART"   , chart_atom_tab   },
  { MORG_PID    , "MORG"    , morg_atom_tab    },
  { RICH_PID    , "RICH"    , rich_atom_tab    },
  { EXAPI_PID   , "EXAPI"   , exapi_atom_tab   },
  { DOD_PID     , "DOD"     , dod_atom_tab     },
  { RADIO_PID   , "RADIO"   , radio_atom_tab   },
  { PICTALK_PID , "PICTALK" , pictalk_atom_tab },
  { IRC_PID     , "IRC"     , irc_atom_tab     },
  { DOC_PID     , "DOC"     , doc_atom_tab     },
  { CCL_PID     , "CCL"     , ccl_atom_tab     },
  { P3_PID      , "P3"      , p3_atom_tab      },
  { AD_PID      , "AD"      , ad_atom_tab      },
  { APP_PID     , "APP"     , app_atom_tab     },
  { MT_PID      , "MT"      , mt_atom_tab      },
  { MERC_PID    , "MERC"    , merc_atom_tab    },
  { VRM_PID     , "VRM"     , vrm_atom_tab     },
  { WWW_PID     , "WWW"     , www_atom_tab     },
  { JAVA_PID    , "JAVA"    , java_atom_tab    },
  { HFS_PID     , "HFS"     , hfs_atom_tab     },
  { BLANK_PID   , "BLANK"   , blank_atom_tab   },
  { VID_PID     , "VID"     , vid_atom_tab     },
  { ACTIVEX_PID , "ACTIVEX" , activex_atom_tab },
  { SEC_IP_PID  , "SEC_IP"  , sec_ip_atom_tab  },
  { GALLERY_PID , "GALLERY" , gallery_atom_tab },
  { DICE_PID    , "DICE"    , dice_atom_tab    },
  { PHONE_PID   , "PHONE"   , phone_atom_tab   },
  { SPELL_PID   , "SPELL"   , spell_atom_tab   },
  { ARTEXP_PID  , "ARTEXP"  , artexp_atom_tab  },
  { MF_PID      , "MF"      , mf_atom_tab      },
  { PLUGIN_PID  , "PLUGIN"  , plugin_atom_tab  },
  { SLIDER_PID  , "SLIDER"  , slider_atom_tab  },
  { ADP_PID     , "ADP"     , adp_atom_tab     },
  { MAP_PID     , "MAP"     , map_atom_tab     },
  { SAGE_PID    , "SAGE"    , sage_atom_tab    },
  { BUDDY_PID   , "BUDDY"   , buddy_atom_tab   },
  { COMIT_PID   , "COMIT"   , comit_atom_tab   },
  { HTMLVIEW_PID, "HTMLVIEW", htmlview_atom_tab},
  { DPC_PID     , "DPC"     , dpc_atom_tab     },
  { SAP_PID     , "SAP"     , sap_atom_tab     },
  { -1          , NULL      , NULL             }
};
