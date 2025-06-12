{
  "targets": [
    {
      "target_name": "eu-sign-node",
      "sources": [
        "src/addon.cpp",
        "src/helpers/helpers.cpp",
        "src/vendor/EUSignCP.cpp",
        "src/data_mappers/data_mappers.cpp",
        "src/eu_sign_node/eu_sign_node.cpp",
        ### EuSing methods
        "src/eu_sign_node/methods/initialize.cpp",
        "src/eu_sign_node/methods/set_settings.cpp",
        "src/eu_sign_node/methods/verify_data_internal.cpp",
        "src/eu_sign_node/methods/get_error_message.cpp",
      ],
      "dependencies": [
        "<!(node -p \"require('node-addon-api').targets\"):node_addon_api_except_all",
      ]
    }
  ]
}
