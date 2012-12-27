<?php
/**
 * @file
 * Block module integration.
 */

/**
 * Implements hook_block().
 */
function admin_select_block($op = 'list', $delta = 0, $edit = array()) {
  switch ($op) {
    case 'list':
      $blocks = array();
      $blocks[] = array(
        'info' => t('Administration Menu select'),
        'admin' => TRUE,
      );
      return $blocks;

    case 'view':
      if (function_exists($function = "admin_select_block_{$delta}_view")) {
        return $function();
      }
      return FALSE;
  }
}

/**
 * Administration Menu select block.
 */
function admin_select_block_0_view() {
  $info = admin_select_get_admin_select_info();
  $options = array();
  foreach ($info as $key => $item) {
    if (!empty($item['access'])) {
      $options[$key] = $item['title'];
    }
  }
  asort($options);
  if (!empty($options)) {
    return array(
      'subject' => t('Administration Menu select'),
      'content' => drupal_get_form('admin_select_block_form', $options),
    );
  }
  return FALSE;
}

/**
 * Administration Menu select block form.
 */
function admin_select_block_form(&$form_state, $options) {
  $data = unserialize($GLOBALS['user']->data);
  $form = array();
  $form['admin_select'] = array(
    '#type' => 'select',
    '#options' => array('' => t('None')) + $options,
    '#default_value' => isset($data['admin_select']) ? $data['admin_select'] : '',
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Switch'),
  );
  return $form;
}

/**
 * Administration Menu select block form submit callback.
 */
function admin_select_block_form_submit($form, $form_state) {
  user_save($GLOBALS['user'], array('admin_select' => $form_state['values']['admin_select']));
}
