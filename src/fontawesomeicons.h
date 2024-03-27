#ifndef FONTAWESOMEICONS_H
#define FONTAWESOMEICONS_H

#include <QFont>
#include <QChar>

class FontAwesomeIcons {
public:
enum class IconIdentity : int {
icon_glass = 0xf000,
icon_music = 0xf001,
icon_search = 0xf002,
icon_envelope_o = 0xf003,
icon_heart = 0xf004,
icon_star = 0xf005,
icon_star_o = 0xf006,
icon_user = 0xf007,
icon_film = 0xf008,
icon_th_large = 0xf009,
icon_th = 0xf00a,
icon_th_list = 0xf00b,
icon_check = 0xf00c,
icon_remove = 0xf00d,
icon_close = icon_remove,
icon_times = icon_remove,
icon_search_plus = 0xf00e,
icon_search_minus = 0xf010,
icon_power_off = 0xf011,
icon_signal = 0xf012,
icon_gear = 0xf013,
icon_cog = icon_gear,
icon_trash_o = 0xf014,
icon_home = 0xf015,
icon_file_o = 0xf016,
icon_clock_o = 0xf017,
icon_road = 0xf018,
icon_download = 0xf019,
icon_arrow_circle_o_down = 0xf01a,
icon_arrow_circle_o_up = 0xf01b,
icon_inbox = 0xf01c,
icon_play_circle_o = 0xf01d,
icon_rotate_right = 0xf01e,
icon_repeat = icon_rotate_right,
icon_refresh = 0xf021,
icon_list_alt = 0xf022,
icon_lock = 0xf023,
icon_flag = 0xf024,
icon_headphones = 0xf025,
icon_volume_off = 0xf026,
icon_volume_down = 0xf027,
icon_volume_up = 0xf028,
icon_qrcode = 0xf029,
icon_barcode = 0xf02a,
icon_tag = 0xf02b,
icon_tags = 0xf02c,
icon_book = 0xf02d,
icon_bookmark = 0xf02e,
icon_print = 0xf02f,
icon_camera = 0xf030,
icon_font = 0xf031,
icon_bold = 0xf032,
icon_italic = 0xf033,
icon_text_height = 0xf034,
icon_text_width = 0xf035,
icon_align_left = 0xf036,
icon_align_center = 0xf037,
icon_align_right = 0xf038,
icon_align_justify = 0xf039,
icon_list = 0xf03a,
icon_dedent = 0xf03b,
icon_outdent = icon_dedent,
icon_indent = 0xf03c,
icon_video_camera = 0xf03d,
icon_photo = 0xf03e,
icon_image = icon_photo,
icon_picture_o = icon_photo,
icon_pencil = 0xf040,
icon_map_marker = 0xf041,
icon_adjust = 0xf042,
icon_tint = 0xf043,
icon_edit = 0xf044,
icon_pencil_square_o = icon_edit,
icon_share_square_o = 0xf045,
icon_check_square_o = 0xf046,
icon_arrows = 0xf047,
icon_step_backward = 0xf048,
icon_fast_backward = 0xf049,
icon_backward = 0xf04a,
icon_play = 0xf04b,
icon_pause = 0xf04c,
icon_stop = 0xf04d,
icon_forward = 0xf04e,
icon_fast_forward = 0xf050,
icon_step_forward = 0xf051,
icon_eject = 0xf052,
icon_chevron_left = 0xf053,
icon_chevron_right = 0xf054,
icon_plus_circle = 0xf055,
        icon_minus_circle = 0xf056,
        icon_times_circle = 0xf057,
        icon_check_circle = 0xf058,
        icon_question_circle = 0xf059,
        icon_info_circle = 0xf05a,
        icon_crosshairs = 0xf05b,
        icon_times_circle_o = 0xf05c,
        icon_check_circle_o = 0xf05d,
        icon_ban = 0xf05e,
        icon_arrow_left = 0xf060,
        icon_arrow_right = 0xf061,
        icon_arrow_up = 0xf062,
        icon_arrow_down = 0xf063,
        icon_mail_forward = 0xf064,
        icon_share = icon_mail_forward,
        icon_expand = 0xf065,
        icon_compress = 0xf066,
        icon_plus = 0xf067,
        icon_minus = 0xf068,
        icon_asterisk = 0xf069,
        icon_exclamation_circle = 0xf06a,
        icon_gift = 0xf06b,
        icon_leaf = 0xf06c,
        icon_fire = 0xf06d,
        icon_eye = 0xf06e,
        icon_eye_slash = 0xf070,
        icon_warning = 0xf071,
        icon_exclamation_triangle = icon_warning,
        icon_plane = 0xf072,
        icon_calendar = 0xf073,
        icon_random = 0xf074,
        icon_comment = 0xf075,
        icon_magnet = 0xf076,
        icon_chevron_up = 0xf077,
        icon_chevron_down = 0xf078,
        icon_retweet = 0xf079,
        icon_shopping_cart = 0xf07a,
        icon_folder = 0xf07b,
        icon_folder_open = 0xf07c,
        icon_arrows_v = 0xf07d,
        icon_arrows_h = 0xf07e,
        icon_bar_chart_o = 0xf080,
        icon_bar_chart = icon_bar_chart_o,
        icon_twitter_square = 0xf081,
        icon_facebook_square = 0xf082,
        icon_camera_retro = 0xf083,
        icon_key = 0xf084,
        icon_gears = 0xf085,
        icon_cogs = icon_gears,
        icon_comments = 0xf086,
        icon_thumbs_o_up = 0xf087,
        icon_thumbs_o_down = 0xf088,
        icon_star_half = 0xf089,
        icon_heart_o = 0xf08a,
        icon_sign_out = 0xf08b,
        icon_linkedin_square = 0xf08c,
        icon_thumb_tack = 0xf08d,
        icon_external_link = 0xf08e,
        icon_sign_in = 0xf090,
        icon_trophy = 0xf091,
        icon_github_square = 0xf092,
        icon_upload = 0xf093,
        icon_lemon_o = 0xf094,
        icon_phone = 0xf095,
        icon_square_o = 0xf096,
        icon_bookmark_o = 0xf097,
        icon_phone_square = 0xf098,
        icon_twitter = 0xf099,
        icon_facebook_f = 0xf09a,
        icon_facebook = icon_facebook_f,
        icon_github = 0xf09b,
        icon_unlock = 0xf09c,
        icon_credit_card = 0xf09d,
        icon_feed = 0xf09e,
        icon_rss = icon_feed,
        icon_hdd_o = 0xf0a0,
        icon_bullhorn = 0xf0a1,
        icon_bell = 0xf0f3,
        icon_certificate = 0xf0a3,
        icon_hand_o_right = 0xf0a4,
        icon_hand_o_left = 0xf0a5,
        icon_hand_o_up = 0xf0a6,
        icon_hand_o_down = 0xf0a7,
        icon_arrow_circle_left = 0xf0a8,
        icon_arrow_circle_right = 0xf0a9,
        icon_arrow_circle_up = 0xf0aa,
        icon_arrow_circle_down = 0xf0ab,
        icon_globe = 0xf0ac,
        icon_wrench = 0xf0ad,
        icon_tasks = 0xf0ae,
        icon_filter = 0xf0b0,
        icon_briefcase = 0xf0b1,
        icon_arrows_alt = 0xf0b2,
        icon_group = 0xf0c0,
        icon_users = icon_group,
        icon_chain = 0xf0c1,
        icon_link = icon_chain,
        icon_cloud = 0xf0c2,
        icon_flask = 0xf0c3,
        icon_cut = 0xf0c4,
        icon_scissors = icon_cut,
        icon_copy = 0xf0c5,
        icon_files_o = icon_copy,
        icon_paperclip = 0xf0c6,
        icon_save = 0xf0c7,
        icon_floppy_o = icon_save,
        icon_square = 0xf0c8,
        icon_navicon = 0xf0c9,
        icon_reorder = icon_navicon,
        icon_bars = icon_navicon,
        icon_list_ul = 0xf0ca,
        icon_list_ol = 0xf0cb,
        icon_strikethrough = 0xf0cc,
        icon_underline = 0xf0cd,
        icon_table = 0xf0ce,
        icon_magic = 0xf0d0,
        icon_truck = 0xf0d1,
        icon_pinterest = 0xf0d2,
        icon_pinterest_square = 0xf0d3,
        icon_google_plus_square = 0xf0d4,
        icon_google_plus = 0xf0d5,
        icon_money = 0xf0d6,
        icon_caret_down = 0xf0d7,
        icon_caret_up = 0xf0d8,
        icon_caret_left = 0xf0d9,
        icon_caret_right = 0xf0da,
        icon_columns = 0xf0db,
        icon_unsorted = 0xf0dc,
        icon_sort = icon_unsorted,
        icon_sort_down = 0xf0dd,
        icon_sort_desc = icon_sort_down,
        icon_sort_up = 0xf0de,
        icon_sort_asc = icon_sort_up,
        icon_envelope = 0xf0e0,
        icon_linkedin = 0xf0e1,
        icon_rotate_left = 0xf0e2,
        icon_undo = icon_rotate_left,
        icon_legal = 0xf0e3,
        icon_gavel = icon_legal,
        icon_dashboard = 0xf0e4,
        icon_tachometer = icon_dashboard,
        icon_comment_o = 0xf0e5,
        icon_comments_o = 0xf0e6,
        icon_flash = 0xf0e7,
        icon_bolt = icon_flash,
        icon_sitemap = 0xf0e8,
        icon_umbrella = 0xf0e9,
        icon_paste = 0xf0ea,
        icon_clipboard = icon_paste,
        icon_lightbulb_o = 0xf0eb,
        icon_exchange = 0xf0ec,
        icon_cloud_download = 0xf0ed,
        icon_cloud_upload = 0xf0ee,
        icon_user_md = 0xf0f0,
        icon_stethoscope = 0xf0f1,
        icon_suitcase = 0xf0f2,
        icon_bell_o = 0xf0a2,
        icon_coffee = 0xf0f4,
        icon_cutlery = 0xf0f5,
        icon_file_text_o = 0xf0f6,
        icon_building_o = 0xf0f7,
        icon_hospital_o = 0xf0f8,
        icon_ambulance = 0xf0f9,
        icon_medkit = 0xf0fa,
        icon_fighter_jet = 0xf0fb,
        icon_beer = 0xf0fc,
        icon_h_square = 0xf0fd,
        icon_plus_square = 0xf0fe,
        icon_angle_double_left = 0xf100,
        icon_angle_double_right = 0xf101,
        icon_angle_double_up = 0xf102,
        icon_angle_double_down = 0xf103,
        icon_angle_left = 0xf104,
        icon_angle_right = 0xf105,
        icon_angle_up = 0xf106,
        icon_angle_down = 0xf107,
        icon_desktop = 0xf108,
        icon_laptop = 0xf109,
        icon_tablet = 0xf10a,
        icon_mobile_phone = 0xf10b,
        icon_mobile = icon_mobile_phone,
        icon_circle_o = 0xf10c,
        icon_quote_left = 0xf10d,
        icon_quote_right = 0xf10e,
        icon_spinner = 0xf110,
        icon_circle = 0xf111,
        icon_mail_reply = 0xf112,
        icon_reply = icon_mail_reply,
        icon_github_alt = 0xf113,
        icon_folder_o = 0xf114,
        icon_folder_open_o = 0xf115,
        icon_smile_o = 0xf118,
        icon_frown_o = 0xf119,
        icon_meh_o = 0xf11a,
        icon_gamepad = 0xf11b,
        icon_keyboard_o = 0xf11c,
        icon_flag_o = 0xf11d,
        icon_flag_checkered = 0xf11e,
        icon_terminal = 0xf120,
        icon_code = 0xf121,
        icon_mail_reply_all = 0xf122,
        icon_reply_all = icon_mail_reply_all,
        icon_star_half_empty = 0xf123,
        icon_star_half_full = icon_star_half_empty,
        icon_star_half_o = icon_star_half_empty,
        icon_location_arrow = 0xf124,
        icon_crop = 0xf125,
        icon_code_fork = 0xf126,
        icon_unlink = 0xf127,
        icon_chain_broken = icon_unlink,
        icon_question = 0xf128,
        icon_info = 0xf129,
        icon_exclamation = 0xf12a,
        icon_superscript = 0xf12b,
        icon_subscript = 0xf12c,
        icon_eraser = 0xf12d,
        icon_puzzle_piece = 0xf12e,
        icon_microphone = 0xf130,
        icon_microphone_slash = 0xf131,
        icon_shield = 0xf132,
        icon_calendar_o = 0xf133,
        icon_fire_extinguisher = 0xf134,
        icon_rocket = 0xf135,
        icon_maxcdn = 0xf136,
        icon_chevron_circle_left = 0xf137,
        icon_chevron_circle_right = 0xf138,
        icon_chevron_circle_up = 0xf139,
        icon_chevron_circle_down = 0xf13a,
        icon_html5 = 0xf13b,
        icon_css3 = 0xf13c,
        icon_anchor = 0xf13d,
        icon_unlock_alt = 0xf13e,
        icon_bullseye = 0xf140,
        icon_ellipsis_h = 0xf141,
        icon_ellipsis_v = 0xf142,
        icon_rss_square = 0xf143,
        icon_play_circle = 0xf144,
        icon_ticket = 0xf145,
        icon_minus_square = 0xf146,
        icon_minus_square_o = 0xf147,
        icon_level_up = 0xf148,
        icon_level_down = 0xf149,
        icon_check_square = 0xf14a,
        icon_pencil_square = 0xf14b,
        icon_external_link_square = 0xf14c,
        icon_share_square = 0xf14d,
        icon_compass = 0xf14e,
        icon_toggle_down = 0xf150,
        icon_caret_square_o_down = icon_toggle_down,
        icon_toggle_up = 0xf151,
        icon_caret_square_o_up = icon_toggle_up,
        icon_toggle_right = 0xf152,
        icon_caret_square_o_right = icon_toggle_right,
        icon_euro = 0xf153,
        icon_eur = icon_euro,
        icon_gbp = 0xf154,
        icon_dollar = 0xf155,
        icon_usd = icon_dollar,
        icon_rupee = 0xf156,
        icon_inr = icon_rupee,
        icon_cny = 0xf157,
        icon_rmb = icon_cny,
        icon_yen = icon_cny,
        icon_jpy = icon_cny,
        icon_ruble = 0xf158,
        icon_rouble = icon_ruble,
        icon_rub = icon_ruble,
        icon_won = 0xf159,
        icon_krw = icon_won,
        icon_bitcoin = 0xf15a,
        icon_btc = icon_bitcoin,
        icon_file = 0xf15b,
        icon_file_text = 0xf15c,
        icon_sort_alpha_asc = 0xf15d,
        icon_sort_alpha_desc = 0xf15e,
        icon_sort_amount_asc = 0xf160,
        icon_sort_amount_desc = 0xf161,
        icon_sort_numeric_asc = 0xf162,
        icon_sort_numeric_desc = 0xf163,
        icon_thumbs_up = 0xf164,
        icon_thumbs_down = 0xf165,
        icon_youtube_square = 0xf166,
        icon_youtube = 0xf167,
        icon_xing = 0xf168,
        icon_xing_square = 0xf169,
        icon_youtube_play = 0xf16a,
        icon_dropbox = 0xf16b,
        icon_stack_overflow = 0xf16c,
        icon_instagram = 0xf16d,
        icon_flickr = 0xf16e,
        icon_adn = 0xf170,
        icon_bitbucket = 0xf171,
        icon_bitbucket_square = 0xf172,
        icon_tumblr = 0xf173,
        icon_tumblr_square = 0xf174,
        icon_long_arrow_down = 0xf175,
        icon_long_arrow_up = 0xf176,
        icon_long_arrow_left = 0xf177,
        icon_long_arrow_right = 0xf178,
        icon_apple = 0xf179,
        icon_windows = 0xf17a,
        icon_android = 0xf17b,
        icon_linux = 0xf17c,
        icon_dribbble = 0xf17d,
        icon_skype = 0xf17e,
        icon_foursquare = 0xf180,
        icon_trello = 0xf181,
        icon_female = 0xf182,
        icon_male = 0xf183,
        icon_gittip = 0xf184,
        icon_gratipay = icon_gittip,
        icon_sun_o = 0xf185,
        icon_moon_o = 0xf186,
        icon_archive = 0xf187,
        icon_bug = 0xf188,
        icon_vk = 0xf189,
        icon_weibo = 0xf18a,
        icon_renren = 0xf18b,
        icon_pagelines = 0xf18c,
        icon_stack_exchange = 0xf18d,
        icon_arrow_circle_o_right = 0xf18e,
        icon_arrow_circle_o_left = 0xf190,
        icon_toggle_left = 0xf191,
        icon_caret_square_o_left = icon_toggle_left,
        icon_dot_circle_o = 0xf192,
        icon_wheelchair = 0xf193,
        icon_vimeo_square = 0xf194,
        icon_turkish_lira = 0xf195,
        icon_try = icon_turkish_lira,
        icon_plus_square_o = 0xf196,
        icon_space_shuttle = 0xf197,
        icon_slack = 0xf198,
        icon_envelope_square = 0xf199,
        icon_wordpress = 0xf19a,
        icon_openid = 0xf19b,
        icon_institution = 0xf19c,
        icon_bank = icon_institution,
        icon_university = icon_institution,
        icon_mortar_board = 0xf19d,
        icon_graduation_cap = icon_mortar_board,
        icon_yahoo = 0xf19e,
        icon_google = 0xf1a0,
        icon_reddit = 0xf1a1,
        icon_reddit_square = 0xf1a2,
        icon_stumbleupon_circle = 0xf1a3,
        icon_stumbleupon = 0xf1a4,
        icon_delicious = 0xf1a5,
        icon_digg = 0xf1a6,
        icon_pied_piper_pp = 0xf1a7,
        icon_pied_piper_alt = 0xf1a8,
        icon_drupal = 0xf1a9,
        icon_joomla = 0xf1aa,
        icon_language = 0xf1ab,
        icon_fax = 0xf1ac,
        icon_building = 0xf1ad,
        icon_child = 0xf1ae,
        icon_paw = 0xf1b0,
        icon_spoon = 0xf1b1,
        icon_cube = 0xf1b2,
        icon_cubes = 0xf1b3,
        icon_behance = 0xf1b4,
        icon_behance_square = 0xf1b5,
        icon_steam = 0xf1b6,
        icon_steam_square = 0xf1b7,
        icon_recycle = 0xf1b8,
        icon_automobile = 0xf1b9,
        icon_car = icon_automobile,
        icon_cab = 0xf1ba,
        icon_taxi = icon_cab,
        icon_tree = 0xf1bb,
        icon_spotify = 0xf1bc,
        icon_deviantart = 0xf1bd,
        icon_soundcloud = 0xf1be,
        icon_database = 0xf1c0,
        icon_file_pdf_o = 0xf1c1,
        icon_file_word_o = 0xf1c2,
        icon_file_excel_o = 0xf1c3,
        icon_file_powerpoint_o = 0xf1c4,
        icon_file_photo_o = 0xf1c5,
        icon_file_picture_o = icon_file_photo_o,
        icon_file_image_o = icon_file_photo_o,
        icon_file_zip_o = 0xf1c6,
        icon_file_archive_o = icon_file_zip_o,
        icon_file_sound_o = 0xf1c7,
        icon_file_audio_o = icon_file_sound_o,
        icon_file_movie_o = 0xf1c8,
        icon_file_video_o = icon_file_movie_o,
        icon_file_code_o = 0xf1c9,
        icon_vine = 0xf1ca,
        icon_codepen = 0xf1cb,
        icon_jsfiddle = 0xf1cc,
        icon_life_bouy = 0xf1cd,
        icon_life_buoy = icon_life_bouy,
        icon_life_saver = icon_life_bouy,
        icon_support = icon_life_bouy,
        icon_life_ring = icon_life_bouy,
        icon_circle_o_notch = 0xf1ce,
        icon_ra = 0xf1d0,
        icon_resistance = icon_ra,
        icon_rebel = icon_ra,
        icon_ge = 0xf1d1,
        icon_empire = icon_ge,
        icon_git_square = 0xf1d2,
        icon_git = 0xf1d3,
        icon_y_combinator_square = 0xf1d4,
        icon_yc_square = icon_y_combinator_square,
        icon_hacker_news = icon_y_combinator_square,
        icon_tencent_weibo = 0xf1d5,
        icon_qq = 0xf1d6,
        icon_wechat = 0xf1d7,
        icon_weixin = icon_wechat,
        icon_send = 0xf1d8,
        icon_paper_plane = icon_send,
        icon_send_o = 0xf1d9,
        icon_paper_plane_o = icon_send_o,
        icon_history = 0xf1da,
        icon_circle_thin = 0xf1db,
        icon_header = 0xf1dc,
        icon_paragraph = 0xf1dd,
        icon_sliders = 0xf1de,
        icon_share_alt = 0xf1e0,
        icon_share_alt_square = 0xf1e1,
        icon_bomb = 0xf1e2,
        icon_soccer_ball_o = 0xf1e3,
        icon_futbol_o = icon_soccer_ball_o,
        icon_tty = 0xf1e4,
        icon_binoculars = 0xf1e5,
        icon_plug = 0xf1e6,
        icon_slideshare = 0xf1e7,
        icon_twitch = 0xf1e8,
        icon_yelp = 0xf1e9,
        icon_newspaper_o = 0xf1ea,
        icon_wifi = 0xf1eb,
        icon_calculator = 0xf1ec,
        icon_paypal = 0xf1ed,
        icon_google_wallet = 0xf1ee,
        icon_cc_visa = 0xf1f0,
        icon_cc_mastercard = 0xf1f1,
        icon_cc_discover = 0xf1f2,
        icon_cc_amex = 0xf1f3,
        icon_cc_paypal = 0xf1f4,
        icon_cc_stripe = 0xf1f5,
        icon_bell_slash = 0xf1f6,
        icon_bell_slash_o = 0xf1f7,
        icon_trash = 0xf1f8,
        icon_copyright = 0xf1f9,
        icon_at = 0xf1fa,
        icon_eyedropper = 0xf1fb,
        icon_paint_brush = 0xf1fc,
        icon_birthday_cake = 0xf1fd,
        icon_area_chart = 0xf1fe,
        icon_pie_chart = 0xf200,
        icon_line_chart = 0xf201,
        icon_lastfm = 0xf202,
        icon_lastfm_square = 0xf203,
        icon_toggle_off = 0xf204,
        icon_toggle_on = 0xf205,
        icon_bicycle = 0xf206,
        icon_bus = 0xf207,
        icon_ioxhost = 0xf208,
        icon_angellist = 0xf209,
        icon_cc = 0xf20a,
        icon_shekel = 0xf20b,
        icon_sheqel = icon_shekel,
        icon_ils = icon_shekel,
        icon_meanpath = 0xf20c,
        icon_buysellads = 0xf20d,
        icon_connectdevelop = 0xf20e,
        icon_dashcube = 0xf210,
        icon_forumbee = 0xf211,
        icon_leanpub = 0xf212,
        icon_sellsy = 0xf213,
        icon_shirtsinbulk = 0xf214,
        icon_simplybuilt = 0xf215,
        icon_skyatlas = 0xf216,
        icon_cart_plus = 0xf217,
        icon_cart_arrow_down = 0xf218,
        icon_diamond = 0xf219,
        icon_ship = 0xf21a,
        icon_user_secret = 0xf21b,
        icon_motorcycle = 0xf21c,
        icon_street_view = 0xf21d,
        icon_heartbeat = 0xf21e,
        icon_venus = 0xf221,
        icon_mars = 0xf222,
        icon_mercury = 0xf223,
        icon_intersex = 0xf224,
        icon_transgender = icon_intersex,
        icon_transgender_alt = 0xf225,
        icon_venus_double = 0xf226,
        icon_mars_double = 0xf227,
        icon_venus_mars = 0xf228,
        icon_mars_stroke = 0xf229,
        icon_mars_stroke_v = 0xf22a,
        icon_mars_stroke_h = 0xf22b,
        icon_neuter = 0xf22c,
        icon_genderless = 0xf22d,
        icon_facebook_official = 0xf230,
        icon_pinterest_p = 0xf231,
        icon_whatsapp = 0xf232,
        icon_server = 0xf233,
        icon_user_plus = 0xf234,
        icon_user_times = 0xf235,
        icon_hotel = 0xf236,
        icon_bed = icon_hotel,
        icon_viacoin = 0xf237,
        icon_train = 0xf238,
        icon_subway = 0xf239,
        icon_medium = 0xf23a,
        icon_yc = 0xf23b,
        icon_y_combinator = icon_yc,
        icon_optin_monster = 0xf23c,
        icon_opencart = 0xf23d,
        icon_expeditedssl = 0xf23e,
        icon_battery_4 = 0xf240,
        icon_battery = icon_battery_4,
        icon_battery_full = icon_battery_4,
        icon_battery_3 = 0xf241,
        icon_battery_three_quarters = icon_battery_3,
        icon_battery_2 = 0xf242,
        icon_battery_half = icon_battery_2,
        icon_battery_1 = 0xf243,
        icon_battery_quarter = icon_battery_1,
        icon_battery_0 = 0xf244,
        icon_battery_empty = icon_battery_0,
        icon_mouse_pointer = 0xf245,
        icon_i_cursor = 0xf246,
        icon_object_group = 0xf247,
        icon_object_ungroup = 0xf248,
        icon_sticky_note = 0xf249,
        icon_sticky_note_o = 0xf24a,
        icon_cc_jcb = 0xf24b,
        icon_cc_diners_club = 0xf24c,
        icon_clone = 0xf24d,
        icon_balance_scale = 0xf24e,
        icon_hourglass_o = 0xf250,
        icon_hourglass_1 = 0xf251,
        icon_hourglass_start = icon_hourglass_1,
        icon_hourglass_2 = 0xf252,
        icon_hourglass_half = icon_hourglass_2,
        icon_hourglass_3 = 0xf253,
        icon_hourglass_end = icon_hourglass_3,
        icon_hourglass = 0xf254,
        icon_hand_grab_o = 0xf255,
        icon_hand_rock_o = icon_hand_grab_o,
        icon_hand_stop_o = 0xf256,
        icon_hand_paper_o = icon_hand_stop_o,
        icon_hand_scissors_o = 0xf257,
        icon_hand_lizard_o = 0xf258,
        icon_hand_spock_o = 0xf259,
        icon_hand_pointer_o = 0xf25a,
        icon_hand_peace_o = 0xf25b,
        icon_trademark = 0xf25c,
        icon_registered = 0xf25d,
        icon_creative_commons = 0xf25e,
        icon_gg = 0xf260,
        icon_gg_circle = 0xf261,
        icon_tripadvisor = 0xf262,
        icon_odnoklassniki = 0xf263,
        icon_odnoklassniki_square = 0xf264,
        icon_get_pocket = 0xf265,
        icon_wikipedia_w = 0xf266,
        icon_safari = 0xf267,
        icon_chrome = 0xf268,
        icon_firefox = 0xf269,
        icon_opera = 0xf26a,
        icon_internet_explorer = 0xf26b,
        icon_tv = 0xf26c,
        icon_television = icon_tv,
        icon_contao = 0xf26d,
        icon_500px = 0xf26e,
        icon_amazon = 0xf270,
        icon_calendar_plus_o = 0xf271,
        icon_calendar_minus_o = 0xf272,
        icon_calendar_times_o = 0xf273,
        icon_calendar_check_o = 0xf274,
        icon_industry = 0xf275,
        icon_map_pin = 0xf276,
        icon_map_signs = 0xf277,
        icon_map_o = 0xf278,
        icon_map = 0xf279,
        icon_commenting = 0xf27a,
        icon_commenting_o = 0xf27b,
        icon_houzz = 0xf27c,
        icon_vimeo = 0xf27d,
        icon_black_tie = 0xf27e,
        icon_fonticons = 0xf280,
        icon_reddit_alien = 0xf281,
        icon_edge = 0xf282,
        icon_credit_card_alt = 0xf283,
        icon_codiepie = 0xf284,
        icon_modx = 0xf285,
        icon_fort_awesome = 0xf286,
        icon_usb = 0xf287,
        icon_product_hunt = 0xf288,
        icon_mixcloud = 0xf289,
        icon_scribd = 0xf28a,
        icon_pause_circle = 0xf28b,
        icon_pause_circle_o = 0xf28c,
        icon_stop_circle = 0xf28d,
        icon_stop_circle_o = 0xf28e,
        icon_shopping_bag = 0xf290,
        icon_shopping_basket = 0xf291,
        icon_hashtag = 0xf292,
        icon_bluetooth = 0xf293,
        icon_bluetooth_b = 0xf294,
        icon_percent = 0xf295,
        icon_gitlab = 0xf296,
        icon_wpbeginner = 0xf297,
        icon_wpforms = 0xf298,
        icon_envira = 0xf299,
        icon_universal_access = 0xf29a,
        icon_wheelchair_alt = 0xf29b,
        icon_question_circle_o = 0xf29c,
        icon_blind = 0xf29d,
        icon_audio_description = 0xf29e,
        icon_volume_control_phone = 0xf2a0,
        icon_braille = 0xf2a1,
        icon_assistive_listening_systems = 0xf2a2,
        icon_asl_interpreting = 0xf2a3,
        icon_american_sign_language_interpreting = icon_asl_interpreting,
        icon_deafness = 0xf2a4,
        icon_hard_of_hearing = icon_deafness,
        icon_deaf = icon_deafness,
        icon_glide = 0xf2a5,
        icon_glide_g = 0xf2a6,
        icon_signing = 0xf2a7,
        icon_sign_language = icon_signing,
        icon_low_vision = 0xf2a8,
        icon_viadeo = 0xf2a9,
        icon_viadeo_square = 0xf2aa,
        icon_snapchat = 0xf2ab,
        icon_snapchat_ghost = 0xf2ac,
        icon_snapchat_square = 0xf2ad,
        icon_pied_piper = 0xf2ae,
        icon_first_order = 0xf2b0,
        icon_yoast = 0xf2b1,
        icon_themeisle = 0xf2b2,
        icon_google_plus_circle = 0xf2b3,
        icon_google_plus_official = icon_google_plus_circle,
        icon_fa = 0xf2b4,
        icon_font_awesome = icon_fa,
        icon_handshake_o = 0xf2b5,
        icon_envelope_open = 0xf2b6,
        icon_envelope_open_o = 0xf2b7,
        icon_linode = 0xf2b8,
        icon_address_book = 0xf2b9,
        icon_address_book_o = 0xf2ba,
        icon_vcard = 0xf2bb,
        icon_address_card = icon_vcard,
        icon_vcard_o = 0xf2bc,
        icon_address_card_o = icon_vcard_o,
        icon_user_circle = 0xf2bd,
        icon_user_circle_o = 0xf2be,
        icon_user_o = 0xf2c0,
        icon_id_badge = 0xf2c1,
        icon_drivers_license = 0xf2c2,
        icon_id_card = icon_drivers_license,
        icon_drivers_license_o = 0xf2c3,
        icon_id_card_o = icon_drivers_license_o,
        icon_quora = 0xf2c4,
        icon_free_code_camp = 0xf2c5,
        icon_telegram = 0xf2c6,
        icon_thermometer_4 = 0xf2c7,
        icon_thermometer = icon_thermometer_4,
        icon_thermometer_full = icon_thermometer_4,
        icon_thermometer_3 = 0xf2c8,
        icon_thermometer_three_quarters = icon_thermometer_3,
        icon_thermometer_2 = 0xf2c9,
        icon_thermometer_half = icon_thermometer_2,
        icon_thermometer_1 = 0xf2ca,
        icon_thermometer_quarter = icon_thermometer_1,
        icon_thermometer_0 = 0xf2cb,
        icon_thermometer_empty = icon_thermometer_0,
        icon_shower = 0xf2cc,
        icon_bathtub = 0xf2cd,
        icon_s15 = icon_bathtub,
        icon_bath = icon_bathtub,
        icon_podcast = 0xf2ce,
        icon_window_maximize = 0xf2d0,
        icon_window_minimize = 0xf2d1,
        icon_window_restore = 0xf2d2,
        icon_times_rectangle = 0xf2d3,
        icon_window_close = icon_times_rectangle,
        icon_times_rectangle_o = 0xf2d4,
        icon_window_close_o = icon_times_rectangle_o,
        icon_bandcamp = 0xf2d5,
        icon_grav = 0xf2d6,
        icon_etsy = 0xf2d7,
        icon_imdb = 0xf2d8,
        icon_ravelry = 0xf2d9,
        icon_eercast = 0xf2da,
        icon_microchip = 0xf2db,
        icon_snowflake_o = 0xf2dc,
        icon_superpowers = 0xf2dd,
        icon_wpexplorer = 0xf2de,
        icon_meetup = 0xf2e0,
        turn_up = 0xf3bf
    };

public:
    static FontAwesomeIcons &Instance();

    QFont getFont();

    QChar getIconChar(FontAwesomeIcons::IconIdentity code);

protected:
    FontAwesomeIcons();

    FontAwesomeIcons(const FontAwesomeIcons &fai) = delete;

    FontAwesomeIcons &operator=(const FontAwesomeIcons &fai) = delete;

private:
    QFont font;
};

#endif // FONTAWESOMEICONS_H

