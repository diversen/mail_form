<?php

$_INSTALL['VERSION'] = 2.41;

$_INSTALL['PUBLIC_CLONE_URL'] = 'git://github.com/diversen/mail_form.git';
$_INSTALL['PRIVATE_CLONE_URL'] = 'git@github.com:diversen/mail_form.git';

if (config::getModuleIni('mail_form_main_menu')) {

    $_INSTALL['MAIN_MENU_ITEM'] = array (
        'title' => lang::translate('mail_form_main_menu', null, array ('no_translate' => true)),
        'url' => '/mail_form/index',
        'module_name' => 'mail_form',
        'parent' => 0,
        'weight' => 2,
    );
}
