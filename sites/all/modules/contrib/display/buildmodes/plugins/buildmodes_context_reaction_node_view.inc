<?php

/**
 * Expose build modes as context reactions.
 */
class buildmodes_context_reaction_node_view extends context_reaction {

  function options_form($context) {
    $form = array();
    $options = array();
    $build_modes = buildmodes_list_modes(TRUE);

    foreach ($build_modes as $name => $build_mode) {
      $options[$name] = $build_mode['title'];
    }

    $form['buildmodes'] = array(
      '#title' => t('Build modes'),
      '#description' => t('Select the build mode for the node being viewed.'),
      '#type' => 'select',
      '#options' => $options,
      '#default_value' => $this->fetch_from_context($context),
    );

    return $form;
  }

  function execute($node) {
    foreach ($this->get_contexts() as $k => $v) {
      // Additionally check that node type conditions are met: if we are viewing
      // multiple nodes and we have multiple node type conditions, the reaction
      // is defined even if the node type condition is met for a different node.
      // Hence we need to check if node type condition is actually met for the
      // current node type.
      if (!empty($v->reactions[$this->plugin]) && (empty($v->conditions['node']) || in_array($node->type, $v->conditions['node']['values']))) {
        $node->build_mode = $v->reactions[$this->plugin]['buildmodes'];
      }
    }
  }
}
