<?php
/**
 * @file
 * Toolbar module integration.
 */

if (!function_exists('toolbar_admin_select_info')) {
  /**
   * Implements hook_admin_select_info() on behalf of toolbar.module.
   */
  function toolbar_admin_select_info() {
    $info = array();

    $info['toolbar'] = array(
      'title' => t('Toolbar module'),
      'access arguments' => array('select toolbar'),
      'suppress callback' => 'toolbar_suppress',
    );

    return $info;
  }
}
