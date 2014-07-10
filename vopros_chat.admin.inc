<?php
/**
 * @file
 * Administrative pages for vopros_chat.
 */

/**
 * Form callback.
 *
 * Settings form.
 */
function vopros_chat_setting_form($form, &$form_state) {
  $form['vopros_chat_open'] = array(
    '#type' => 'radios',
    '#title' => t('Chat open'),
    '#options' => array(
      'open' => t('Yes'),
      'closed' => t('No'),
    ),
    '#description' => t('Whether the chat is currently open.'),
    '#default_value' => variable_get('vopros_chat_open', 0),
  );

  $form['vopros_chat_closed_message'] = array(
    '#type' => 'textarea',
    '#title' => t('Close message'),
    '#description' => t('Message sendt to the user when the editor closes the chat.'),
    '#default_value' => variable_get('vopros_chat_closed_message', 'Chat closed'),
  );

  return system_settings_form($form);
}