<?php
/**
 * @file
 * vopros_chat.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function vopros_chat_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'vopros_chat_question_list';
  $view->description = 'Used to display questions, to find the ones that can/should be answered';
  $view->tag = 'default';
  $view->base_table = 'vopros_question';
  $view->human_name = 'Chat Question list';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Question list';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access questions';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'question_id' => 'question_id',
    'user_name' => 'user_name',
    'label' => 'label',
    'created' => 'created',
    'chat_status' => 'chat_status',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'question_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'user_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'label' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'chat_status' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Footer: Question: Views Count */
  $handler->display->display_options['footer']['views_count']['id'] = 'views_count';
  $handler->display->display_options['footer']['views_count']['table'] = 'vopros_question';
  $handler->display->display_options['footer']['views_count']['field'] = 'views_count';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Ingen aktive chats.';
  $handler->display->display_options['empty']['area']['format'] = 'wysiwyg';
  /* Relationship: Question: Feedback */
  $handler->display->display_options['relationships']['feedback_question_id']['id'] = 'feedback_question_id';
  $handler->display->display_options['relationships']['feedback_question_id']['table'] = 'vopros_question';
  $handler->display->display_options['relationships']['feedback_question_id']['field'] = 'feedback_question_id';
  /* Relationship: Question: Question client */
  $handler->display->display_options['relationships']['client_id']['id'] = 'client_id';
  $handler->display->display_options['relationships']['client_id']['table'] = 'vopros_question';
  $handler->display->display_options['relationships']['client_id']['field'] = 'client_id';
  /* Field: Question: Question ID */
  $handler->display->display_options['fields']['question_id']['id'] = 'question_id';
  $handler->display->display_options['fields']['question_id']['table'] = 'vopros_question';
  $handler->display->display_options['fields']['question_id']['field'] = 'question_id';
  $handler->display->display_options['fields']['question_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['question_id']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['question_id']['separator'] = '';
  /* Field: Question: User_name */
  $handler->display->display_options['fields']['user_name']['id'] = 'user_name';
  $handler->display->display_options['fields']['user_name']['table'] = 'vopros_question';
  $handler->display->display_options['fields']['user_name']['field'] = 'user_name';
  $handler->display->display_options['fields']['user_name']['label'] = 'Name';
  $handler->display->display_options['fields']['user_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['user_name']['alter']['path'] = 'admin/vopros/questions/[question_id]';
  /* Field: Client: Label */
  $handler->display->display_options['fields']['label']['id'] = 'label';
  $handler->display->display_options['fields']['label']['table'] = 'vopros_question_client';
  $handler->display->display_options['fields']['label']['field'] = 'label';
  $handler->display->display_options['fields']['label']['relationship'] = 'client_id';
  $handler->display->display_options['fields']['label']['label'] = 'Received from';
  $handler->display->display_options['fields']['label']['element_label_colon'] = FALSE;
  /* Field: Question: Created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'vopros_question';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  /* Field: Question: Chat status */
  $handler->display->display_options['fields']['chat_status']['id'] = 'chat_status';
  $handler->display->display_options['fields']['chat_status']['table'] = 'vopros_question';
  $handler->display->display_options['fields']['chat_status']['field'] = 'chat_status';
  /* Sort criterion: Question: Created */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'vopros_question';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Question: User_answer_preference */
  $handler->display->display_options['filters']['user_answer_preference']['id'] = 'user_answer_preference';
  $handler->display->display_options['filters']['user_answer_preference']['table'] = 'vopros_question';
  $handler->display->display_options['filters']['user_answer_preference']['field'] = 'user_answer_preference';
  $handler->display->display_options['filters']['user_answer_preference']['value'] = array(
    'chat' => 'chat',
  );
  $handler->display->display_options['filters']['user_answer_preference']['group'] = 1;
  /* Filter criterion: Question: Question_status */
  $handler->display->display_options['filters']['question_status']['id'] = 'question_status';
  $handler->display->display_options['filters']['question_status']['table'] = 'vopros_question';
  $handler->display->display_options['filters']['question_status']['field'] = 'question_status';
  $handler->display->display_options['filters']['question_status']['value'] = array(
    'new' => 'new',
    'active' => 'active',
    'assigned' => 'assigned',
  );
  $translatables['vopros_chat_question_list'] = array(
    t('Master'),
    t('Question list'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Ingen aktive chats.'),
    t('question'),
    t('Question client'),
    t('Question ID'),
    t('.'),
    t('Name'),
    t('Received from'),
    t('Created'),
    t('Chat status'),
  );
  $export['vopros_chat_question_list'] = $view;

  return $export;
}
