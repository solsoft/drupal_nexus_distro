
-- SUMMARY --

The Drupal Build modes module allows a site administrator to add
node build modes via the administration user interface.

What is a build mode?

Where you are browsing a Drupal page with an URL like taxonomy/term/3
Drupal renders by default nodes in the build mode 'teaser'. And when
you are browsing a page like 'node/1' Drupal renders the build mode 'full',
which is the complete node.

Several modules ships with extra build modes, like the search module, the
print module, etc.

-- REQUIREMENTS --

CCK: content module

-- INSTALLATION --

* Install as usual, see http://drupal.org/node/70151 for further information.

-- CONFIGURATION --

Go to Site building > Build modes

From here you can add/edit/delete build modes

You can use your defined build modes with the Views module, simply tick the
appropriate option in the edit form.

-- What to do once a build mode is created? --

As you have seen each build mode comes with one (in fact severals) template
suggestions. It means that in your theme, you can create new template files.

Let say you just defined a build mode called 'Featured' with a system name
'featured'. And let say you have a content type called 'story'. In your theme,
can now create a template called: node-story-featured.tpl.php

Now you can create a new View, say 'Featured stories' with for example a block
display. You can set the 'Row style' option to 'node' and choose one of the available
build modes you just created (Featured in our example).

Note that your defined build modes are also available and customizable at
Content management > Content types > [whatever] > Display fields > Build modes

The module also provides node reference field formatters for each of your custom
build modes. This extends node reference field formatters beyond title (link),
title (no link), full and teaser. For example, if you have a story node
with a node reference field to link a person node, you can format that node
reference field with an author build mode that you implement.

For developers, buildmodes_node_view() is a substitute for core node_view() but
takes a build mode as an argument instead of teaser and page booleans.

For a full description of the module, visit the project page:
  http://drupal.org/project/buildmodes

To submit bug reports and feature suggestions, or to track changes:
  http://drupal.org/project/issues/buildmodes
