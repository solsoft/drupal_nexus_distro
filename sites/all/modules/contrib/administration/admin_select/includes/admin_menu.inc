<?php
/**
 * @file
 * Administration menu module integration.
 */

if (!function_exists('admin_menu_admin_select_info')) {
  /**
   * Implements hook_admin_select_info() on behalf of admin_menu.module.
   */
  function admin_menu_admin_select_info() {
    $info = array();

    $info['admin_menu'] = array(
      'title' => t('Administration menu module'),
      'access arguments' => array('access administration menu'),
      'suppress callback' => 'admin_menu_suppress',
    );

    return $info;
  }
}

/**
 * Implements hook_admin_menu().
 */
function admin_select_admin_menu(&$deleted) {
  $links = array();
  $icon_path = '<front>';

  $links[] = array(
    'title' => 'Administration Menu select',
    'path' => 'admin_select',
    'weight' => 50,
    'parent_path' => $icon_path,
  );
  $links[] = array(
    'title' => 'None',
    'path' => 'admin_select/none',
    'weight' => 0,
    'parent_path' => 'admin_select',
  );

  $info = admin_select_get_admin_select_info();
  asort($info);
  foreach ($info as $key => $item) {
    $links[] = array(
      'title' => $item['title'],
      'path' => "admin_select/{$key}",
      'weight' => 10,
      'parent_path' => 'admin_select',
    );
  }

  return $links;
}
