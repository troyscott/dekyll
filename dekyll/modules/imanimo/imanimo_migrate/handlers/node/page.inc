<?php

/**
 * Migrate Page nodes.
 */
class ImanimoPageNodes extends ImanimoMigration {
  public $csvColumns = array(
    array('language', 'Language'),
    array('path', 'Path'),
    array('link_weight', 'Link weight'),
    array('body', 'Body'),
  );

  public $entityType = 'node';
  public $bundle = 'page';

  public $dependencies = array(
    'ImanimoCommerceProducts',
  );

  public function __construct() {
    parent::__construct();

    $this->addFieldMapping('body', 'body')
      ->arguments(array('format' => 'full_html'));;

    $this
      ->addFieldMapping('field_category', 'field_category')
      ->sourceMigration('ImanimoOfferCategoriesTerms');

    $this->addFieldMapping('language', 'language');
    $this->addFieldMapping('path', 'path');
  }
}