<?php

/**
 * @file
 * Build modes page callbacks.
 */

/**
 * Menu callback; view a single node.
 */
function buildmodes_page_view($node, $build_mode = NODE_BUILD_NORMAL) {
  $modes = buildmodes_list_modes(TRUE);
  drupal_set_title($modes[$build_mode]['title']);
  return buildmodes_node_view($node, $build_mode);
}
